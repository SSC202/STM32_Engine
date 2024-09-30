# Engine 5.2.1 Odrive配置参数和系统指令

将使用`<odrv>`作为每个ODrive对象的占位符。 每个ODrive控制器都是一个ODrive对象。 在`odrivetool` 中通常是 `odrv0`。 此外，将`<axis>`用作每个轴的占位符，这是 ODrive 对象的属性（例如`odrv0.axis0`）。 轴表示电动机的连接位置。（M0 和 `axis0` 对应，M1 和 `axis1`对应）。

## 1. 轴指令

在大多数情况下，可以单独控制 ODrive 上的两个轴。

轴的当前状态由`<axis>.current_state`指示。 用户可以使用`<axis>.requested_state`请求切换到其它状态。 启动后的默认状态为`AXIS_STATE_IDLE`。

1. `AXIS_STATE_IDLE`：禁用电机PWM，不执行任何操作。

2. `AXIS_STATE_STARTUP_SEQUENCE`：运行启动程序。

3. `AXIS_STATE_FULL_CALIBRATION_SEQUENCE`：运行电机校准，编码器偏移校准(如果编码器索引信号启用的话同时进行索引信号的搜索，如果要启用编码器索引脉冲信号设置 `<axis>.encoder.config.use_index` 为 `True` 即可)。

4. `AXIS_STATE_MOTOR_CALIBRATION`：测量电机的相电阻和相电感。

   > - 要存储测量结果，请将`<axis>.motor.config.pre_calibrated`设置为`True`，然后保存配置。 之后无需在下次启动时运行电机校准。
   > - 运行此测量之后 `<axis>.motor.config.phase_resistance` 和 `<axis>.motor.config.phase_inductance` 将会被修改。

5. `AXIS_STATE_SENSORLESS_CONTROL`：启动无传感器运行。
   > - 确保电机已经被校准（`<axis>.motor.is_calibrated` 为 `True`）;
   - 确保`<axis>.controller.control_mode` 已被正确配置。

6. `AXIS_STATE_ENCODER_INDEX_SEARCH`：电机沿一个方向旋转，直到搜索到编码器索引。 仅当`<axis> .encoder.config.use_index ` 为 `True`时才能进入此状态。

7. `AXIS_STATE_ENCODER_OFFSET_CALIBRATION`：电机沿一个方向旋转几秒钟，然后反方向旋转以测量编码器位置和电机电气相位之间的偏移。

   > - 仅当电机已被校准（`<axis> .motor.is_calibrated`为`True`）时才能进入此状态。
   > - 成功执行完编码器校准之后`<axis>.encoder.is_ready`将会变为`True`。

8. `AXIS_STATE_CLOSED_LOOP_CONTROL`：电机闭环运行模式。
   该状态的具体运行和控制模式有关。仅当电机已校准（`<axis> .motor.is_calibrated`）并且编码器已准备好（`<axis> .encoder.is_ready`）时才能进入此状态。

## 2. 启动程序

想要更改启动后的程序，请将想要启动后被执行的项置为True。ODrive启动后将按以下所示被设置为True的进行执行。

> `<axis>.config.startup_motor_calibration`
> `<axis>.config.startup_encoder_index_search`
> `<axis>.config.startup_encoder_offset_calibration`
> `<axis>.config.startup_closed_loop_control`
> `<axis>.config.startup_sensorless_control`

## 3. 控制模式/控制指令

默认控制模式是位置控制。如果要使用其他模式，则可以设置`<axis>.controller.config.control_mode`为如下的任意值：

> `CTRL_MODE_POSITION_CONTROL`
> `CTRL_MODE_VELOCITY_CONTROL`
> `CTRL_MODE_CURRENT_CONTROL`
> `CTRL_MODE_VOLTAGE_CONTROL`

控制指令如下：

> `<axis>.controller.pos_setpoint = <encoder_counts>`
> `<axis>.controller.vel_setpoint = <encoder_counts/s>`
> `<axis>.controller.current_setpoint = <current_in_A>`

## 4. 系统监控指令

1. 编码器位置和速度
   - 使用 `<axis>.encoder.pos_estimate [counts]` 来查看当前编码器的位置；
   - 使用 `<axis>.encoder.vel_estimate [counts/s]` 来查看当前电机转速。
2. 电机电流和转矩估算
   - 使用 `<axis>.motor.current_control.Iq_setpoint [A]` 来查看当前设置的电机电流
   - 使用 `<axis>.motor.current_control.Iq_measured [A]` 来查看当前电机的实际电流，如果发现这个数据有噪声，可以直接用设置的电机电流来替代，因为在给定电压下电机没有达到最大转速的情况下，电机实际电流应该几乎等于设置的电机电流，否则电机的实际电流可能小于设置的目标电流。

## 5. 通用系统指令

1. 保存配置
   所有带有`.config`的变量都可以保存到 ODrive 的非易失性存储器中，因此在断电后它们仍然存在。 相关命令为：
    > - `<odrv>.save_configuration()`: 保存配置到ODrive的非易失性存储器中。
    > - `<odrv>.erase_configuration()`: 将所有配置重置为出厂默认值。仅在重启后才有效。 该命令会使电机停止（如果正在运行），并且USB通信会暂时中断。 这是因为擦除闪存会使微控制器挂起几秒钟。

2. 诊断ODrive

   > - `<odrv>.serial_number`: 唯一标识您ODrive的序列号。 当以大写十六进制(`hex(<odrv> .serial_number).upper()`)打印时，该串序列号与USB描述符指示的序列号相同。
   > - `<odrv>.fw_version_major`,` <odrv>.fw_version_minor`， `<odrv>.fw_version_revision`: ODrive的固件版本。
   > - `<odrv>.hw_version_major`, `<odrv>.hw_version_minor`, `<odrv>.hw_version_revision`: ODrive的硬件版本。