# Engine 5.2.2 Odrive的编码器配置

Odrive 支持的编码器是 ABZ 编码器和 SPI 接口的编码器。

> ODrive 支持两种类型的 SPI绝对值编码器：
>
> 1. CUI 协议：兼容 AMT23xx 系列 (AMT232A, AMT232B, AMT233A, AMT233B)。
> 2. AMS 协议：兼容 AS5047P 和 AS5048A。
>
> (ODrive 并不支持 TLE5012B 的 SPI 接口，仅能使用它的 ABI)

## 1. 编码器校准

ODrive 支持的所有编码器类型都需要进行某种编码器校准。 这需要以下条件：

> 1. 选择一种编码器并将其安装到电动机；
> 2. 选择编码器通讯接口 (AB, ABI or SPI)；
> 3. 将编码器通信接口连接到 ODrive；
> 4. 加载正确的 Odrive 固件（默认的固件大多数情况下都是可以的）；
> 5. 电机校准；
> 6. 将设置保存在ODrive中，并正确启动。

1. 无索引信号的编码器

   在编码器校准过程中，必须允许转子旋转而且不能有偏载。 这意味着载荷均匀和较弱的摩擦载荷才行，但是重载或类似弹簧载荷不行。

   在 `odrivetool`中输入`<axis>.requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION`执行校正。

   `<axis>.error`应该为 0。
   `<axis>.encoder.config.offset`应该打印出一个数字类似 -326 或 1364。
   `<axis>.motor.config.direction` 应该打印出 1 或 -1。

2. 有索引信号的编码器

   如果编码器带有索引（Z）信号，则可以避免每次启动时都必须进行编码器偏移校准，而可以使用索引信号将编码器重新同步到存储的偏移校准。

   以下是进行一次性校准和配置的步骤。

   > 1. 设置 `<axis>.encoder.config.use_index` 为 `True`。
   > 2. 执行 `<axis>.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH`。这将使电机朝一个方向旋转，直到找到编码器索引。
   > 3. 按照无索引信号的编码器校准说明进行操作。
   > 4. 设置 `<axis>.encoder.config.pre_calibrated` 为 `True` 以使能索引脉冲。
   > 5. 如果想在启动时搜索索引信号，请设置 `<axis>.config.startup_encoder_index_search` 为 `True`。
   >    - 如果您希望手动进行操作，请在每次启动ODrive后运行 `<axis>.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH`。
   > 6. 如果希望在启动时尽量的快，请设置`<axis>.motor.config.pre_calibrated` 为 `True` 这样就不需要在每次启动时重新测量电机参数。
   > 7. 执行 `<odrv>.save_configuration()`。
   > 8. 如果电机启动后寻找编码器索引时由于负载过重转不动时，您可以适当增大`<axis>.motor.config.calibration_current`。

   有时，您希望索引搜索仅在特定方向上进行（默认设置的相反），而不是通过交换马达引线来实现，可以将以下三个值设置为负数：
   > `<axis0>.config.calibration_lockin.vel`
   > `<axis0>.config.calibration_lockin.accel`
   > `<axis0>.config.calibration_lockin.ramp_distance`

   如果索引信号工作正常，当 ODrive 执行索引搜索时，电机应该找到相同的旋转位置。 这意味着如果设置了`<axis> .config.startup_encoder_index_search`，则电机应该旋转并停止在相同位置，以便搜索在重新启动时开始，或者在重新启动后调用命令：`<axis> .requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH`。 发送`reboot()`命令，然后在重新启动时转动电机，然后确保每次退出重新索引搜索时电机都旋转到正确的位置。 确保尝试几次此过程。

3. SPI 编码器

   同无索引信号编码器，增加编码器配置：

   ```python
   odrv0.axis0.encoder.config.mode = ENCODER_MODE_SPI_ABS_AMS            # 设置编码器类型
   odrv0.axis0.encoder.config.abs_spi_cs_gpio_pin = 1                    # 选择CS引脚
   odrv0.axis0.encoder.config.cpr = 2**14                                # 14bit
   ```

## 2. 编码器噪声

编码器噪声可能有以下几种来源：

> 1. 编码器线可能太靠近电机线，请尽可能避免重叠；
> 2. 编码器和ODrive之间的连线太长；
> 3. 使用了排线连接编码器和 ODrive ；
> 4. 可以使用屏蔽电缆或双绞线，其中每对双绞线的一侧都接地，另一侧则与信号相连，来减少噪声干扰的影响。 
>    - 如果使用的是SPI，请在 CLK 上串联一个20-50欧姆的电阻，因为 CLK 上更容易被噪声干扰。

如果使用带有索引信号的编码器，则遇到的另一个问题是ODrive的Z输入上的噪声。 此问题的症状如下：

1. 当执行编码器校准时很难成功。
1. 执行完 `odrv0.save_configuration()`和 `odrv0.reboot()`后出现一些奇怪的现象。
1. 在执行索引搜索时，电机每次搜索完成后停在的位置不一致。

一个简单的解决方案是在 ODrive 索引信号输入引脚和 GND 之间增加一个 22nF 到 47nF 的电容。
