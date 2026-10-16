# Maxwell_PMSM 仿真

Ansoft 公司的 Maxwell 是一个功能强大、结果精确、易于使用的二维/三维(2D/3D)电磁场有限元分析软件。它的求解模块包括静电场、静磁场、时变电场、时变磁场、涡流场、瞬态场和温度场计算等,可以用来分析电机、传感器、变压器、水磁设备、激励器等电磁装置的静态、瞬态、稳态、正常工况和故原工况的特性。Maxwell 3D 包括 Maxwell 2D 所有的模块并新增了 3D 应力场分析模块。

Ansys Electronics Desktop 内部集成了 Maxwell 模块，使用此模块可以进行电机本体仿真。

- 稳态场分析和瞬态场分析

  稳态磁场通常包括所有磁场量不随时间变化的静态磁场和激励随时间按正弦或余弦规律变化的涡流磁场。

  在电磁场的实际分析中,当电压、电流无规则变化,即所加载励磁是时间、位置或者速度的函数时,需要采用瞬态分析。瞬态分析的步骤和方法与稳态分析有相近之处,同样分为建模、设置材料属性、设置激励、设置边界杀件、副分设置、求解设置以及查看求解结果等,有时还需要设置被求解问题的运动属性。**一般使用瞬态场分析**。

## 1. 一般仿真示例

1. 新建工程

   ![NULL](./assets/picture_1.jpg)

2. 新建仿真模块

   ![NULL](./assets/picture_2.jpg)

   ![NULL](./assets/picture_3.jpg)

3. 仿真设置

   ![NULL](./assets/picture_4.jpg)

   由于是平面仿真，深度设置为 1mm。

4. 绘制几何模型

   使用 RMxprt 的电机模型。

   ![NULL](./assets/picture_5.jpg)

   定子参数：

   ![NULL](./assets/picture_6.jpg)

   转子参数：

   ![NULL](./assets/picture_7.jpg)

   永磁体复制转子，但是把 `InfoCore` 设置为 1。然后使用 `Edit\Boolean\Separate Bodies` 分离永磁体。

   填充转子线圈，分为左右两侧或者上下两侧均可。

   ![NULL](./assets/picture_8.jpg)

   绘制求解区：inner 覆盖转子，band 为运动区，边界设置在一半气隙处，outter 覆盖整个电机。

   运动区设置：

   ![NULL](./assets/picture_20.jpg)

   设置为 1/4 模型以简化计算。

   ![NULL](./assets/picture_10.jpg)

5. 设置材料

   定转子选择硅钢片 DWxxx。

   永磁体选择 NdFexx，但是需要注意方向：

   ![NULL](./assets/picture_9.jpg)

   绕组使用 copper。

6. 设置边界

   首先设置两个直线边界，使用主从方式设置。

   ![NULL](./assets/picture_11.jpg)

   另一条边：

   ![NULL](./assets/picture_12.jpg)

   圆形边界：

   ![NULL](./assets/picture_13.jpg)

7. 激励设置

   插入 RMxprt 方便配置线圈：

   ![NULL](./assets/picture_14.jpg)

   Mechine 参数(配置极数)：

   ![NULL](./assets/picture_15.jpg)

   Stator 参数(配置槽数)：

   ![NULL](./assets/picture_16.jpg)

   Winding 参数(配置节距)，此时可以看到绕组分布：

   ![NULL](./assets/picture_17.jpg)

   配置线圈：

   ![NULL](./assets/picture_18.jpg)

   配置相数：

   ![NULL](./assets/picture_19.jpg)

   最后将线圈添加到相同的相里面即可。

8. 网格划分

   定子，转子，线圈，永磁体，inner，outter 分别按照默认配置划分网格。band 内网格需要细分。

   ![NULL](./assets/picture_21.jpg)

9. 设置仿真步长和停止时间

   ![NULL](./assets/picture_22.jpg)

10. 开始仿真

    ![NULL](./assets/picture_23.jpg)

11. 观察仿真结果

    比如观察磁场：

    ![NULL](./assets/picture_24.jpg)

    ![NULL](./assets/picture_25.jpg)

    基本示例完成！

    
