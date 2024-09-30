# Engine 5.3.2 Odrive的串口通信

## 1. 串口指令发送

1. 通过 USB：使用 Zadig 将 ODrive 的驱动程序设置为 usbser。 Windows 随后将使该设备识别为 COM 端口。使用编程语言打开COM端口自己编写代码发送指令。
2. 通过 UART：将 ODrive 的 TX(GPIO1) 连接到主机的 RX。 将 ODrive 的 RX(GPIO2) 连接到主机的 TX。 ODrive的逻辑电平为3.3V。

## 2. 串口指令格式

使用ASCII 格式协议方便直接阅读，它的格式如下：

```
command *42 ; 注释 [换行符]
```

> -  `*42`表示兼容 GCode 的校验和，它可以被省略。
> - 注释也是兼容 GCode 。
> - 一旦遇到换行符，将开始解释该指令。

1. 电机轨迹指令
    ```
       t motor destination
    ```

    > - `t` 表示轨迹控制模式。
    > -  `motor` 表示电机编号， 0 或 1。
    > - `destination` 目标位置，值表示编码器的计数。

    对于一般绕轴运动，推荐使用这种命令。以上命令发送后会触发对应电机的内部看门狗喂狗动作。

2. 电机位置指令
    对于一次发送一个设定位置的应用，请使用q命令。
    如果您的应用是实时控制位置，您应该不断的发送处于轨迹上的各个位置，来实现自定义的轨迹跟踪。

    ```
    q motor position velocity_lim current_lim
    ```

    > - `q` 表示位置控制模式。
    > - `motor` 表示电机编号, 0 或 1。
    > - `position` 目标位置，值表示编码器的计数。
    > - `velocity_lim` 转速限制，单位为counts/s （可选的）。
    > - `current_lim` 电流限制，单位为A（可选的）。

    ```
    p motor position velocity_ff current_ff
    ```

    > - `p` 表示位置控制模式。
    > - `motor` 表示电机编号, 0 或 1。
    > - `position` 目标位置，值表示编码器的计数。
    > - `velocity_ff` 速度前馈，单位为counts/s（可选的）。
    > - `current_ff` 电流前馈， 单位为A（可选的）。

3. 电机速度指令
   ```
   v motor velocity current_ff
   ```

   > - `v` 表示速度控制模式。
   > - `motor` 表示电机编号, 0 或 1。
   > - `velocity` 目标转速，单位为 counts/s。
   > - `current_ff` 电流前馈, 单位为 A（可选的）。

4. 电机电流指令
   ```
   c motor current
   ```
   > - `c` 表示电流控制模式。
   > - `motor` 表示电机编号, 0 或 1。
   > - `current` 目标电流，单位为A。

5. 请求状态信息指令

   ```
   f motor
   
   response:
   pos vel
   ```

   > - `f` 表示请求返回信息。
   > - `motor` 表示电机编号, 0 或 1。
   > - `pos` 当前编码器计数值 (float)。
   > - `vel` 当前转速，单位为 counts/s (float)。

6. 参数读/写

   并非所有参数都可以通过ASCII协议读写，但支持所有float和integer类型的参数。

   - 读:

     ```
     r [property]
     ```
   
     > - `property` 属性名称，如ODrive Tool中所示。
     >- `response` 返回所请求参数值的文本表示。
   
   - 写:
   
     ```
     w [property] [value]
     ```
     
     > - `property` 属性名称，如ODrive Tool中所示。
     > - `value` 想要设定的值。

7. 系统指令

   - `ss` - 保存配置.
   - `se` - 擦除配置.
   - `sr` - 重启.
