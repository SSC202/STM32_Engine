# Engine 4.4.2 Chibios 操作系统简介

VESC 使用的 RTOS 是 Chibios，这是一款轻量化的实时操作系统。

Chibios 的官方文档/教程：[链接](https://www.playembedded.org/blog/)

学习 Chibios 的使用和移植之前，可以学习常见的 RTOS (比如 FreeRTOS)  以了解 RTOS 的基本概念。

## 0. Chibios 简介

Chibios 的作者是 Giovanni Di Sirio。Chibi 这个名称在日语是小孩的意思，所以 ChibiOS (ちびOS) 也被可以理解成小型的操作系统。

ChibiOS / RT 于2007年9月份在 SourceForge 公开发布。由于作者对当时现有的RTOS的不满，所以写了这个系统，作者心目中的RTOS应该是：优雅，快速，小型，静态的。这些也是 Chibios 的核心思想与系统的特点。所以专注于代码的优美性和一致性，以及内存的静态使用、确定性、强大的抽象功能，都是这个系统关键的特性。

ChibiOS 系统包含以下组件：

> 1. RT，用于嵌入式实时系统最快的 RTOS 解决方案。
> 2. NIL，用于嵌入式实时系统的最小 RTOS 解决方案。
> 3. OSLIB，高级功能包，可以在两者之上使用。
> 4. SB，Cortex-M4 和 M7 内核独有的扩展。ChibiOS/SB 能够在应用程序代码中创建称为 sandbox（沙箱）的隔离分区。
> 5. HAL，一个包含一组抽象设备驱动程序的包，允许跨不同架构实现有效的应用程序可移植性。
> 6. EX，许多板级外部设备（如 MEMS 等）的设备驱动程序。

## 1. Chibios 移植

### Linux 移植

> Linux 下使用 `make` 命令及其方便，而且 Chibios 例程可以很方便的在 Linux 下运行，所以先使用 Linux 进行移植。

> 开发环境：
>
> - `gcc-arm-none-eabi` 编译链；
> - Linux（Ubuntu 20.04）系统。

1. 首先下载 Chibios 源码：

   ```shell
   $ git clone https://github.com/ChibiOS/ChibiOS.git
   ```

   下载得到的源码文件夹结构大致如下：

   ```
   *****************************************************************************
   *** Files Organization                                                    ***
   *****************************************************************************
   
   --{root}                        - ChibiOS directory.
     +--readme.txt                 - This file.
     +--documentation.html         - Shortcut to the web documentation page.
     +--license.txt                - GPL license text.
     +--demos/                     - 参考例程
     +--docs/                      - Documentation.
     |  +--common/                 - Documentation common build resources.
     |  +--hal/                    - Builders for HAL.
     |  +--nil/                    - Builders for NIL.
     |  +--rt/                     - Builders for RT.
     +--ext/                       - 扩展组件
     +--os/                        - Chibios 系统组件
     |  +--common/                 - Chibios 共享组件
     |  |  +--abstractions/        - API emulator wrappers.
     |  |  |  +--cmsis_os/         - CMSIS-OS 接口
     |  |  |  +--nasa_osal/        - NASA 系统接口
     |  |  +--ext/                 - 操作系统使用的供应商文件
     |  |  +--ports/               - RT/NIL 组件公用接口
     |  |  +--portability/         - RT/NIL 组件公用接口
     |  |  +--startup/             - 芯片启动文件
     |  |  +--oop/					- 面向对象相关文件
     |  +--ex/                     - EX 组件.
     |  |  +--dox/                 - EX documentation resources.
     |  |  +--include/             - EX 头文件.
     |  |  +--devices /            - EX 设备文件.
     |  +--hal/                    - HAL 组件.
     |  |  +--boards/              - HAL 板级驱动文件
     |  |  +--dox/                 - HAL documentation resources.
     |  |  +--include/             - HAL high level headers.
     |  |  +--lib/                 - HAL libraries.
     |  |  |  +--complex/          - HAL collection of complex drivers.
     |  |  |  |  +--mfs/           - HAL managed flash storage driver.
     |  |  |  |  +--serial_nor/    - HAL legacy SNOR stack.
     |  |  |  |  +--xsnor/         - HAL improved SNOR stack.
     |  |  |  +--fallback/         - HAL fall back software drivers.
     |  |  |  +--peripherals/      - HAL peripherals interfaces.
     |  |  |  +--streams/          - HAL streams.
     |  |  +--osal/                - HAL 向操作系统开放的接口
     |  |  |  +--lib/              - HAL OSAL common modules.
     |  |  +--src/                 - HAL high level source.
     |  |  +--ports/               - HAL 硬件接口
     |  |  +--templates/           - HAL driver template files.
     |  |     +--osal/             - HAL OSAL templates.
     |  +--oslib/                  - RT/NIL 公用 RTOS 接口
     |  |  +--include/             - OSLIB high level headers.
     |  |  +--src/                 - OSLIB high level source.
     |  |  +--templates/           - OSLIB configuration template files.
     |  +--nil/                    - NIL 组件.
     |  |  +--dox/                 - NIL documentation resources.
     |  |  +--include/             - NIL high level headers.
     |  |  +--src/                 - NIL high level source.
     |  |  +--templates/           - NIL configuration template files.
     |  +--rt/                     - RT RTOS component.
     |  |  +--dox/                 - RT documentation resources.
     |  |  +--include/             - RT high level headers.
     |  |  +--src/                 - RT high level source.
     |  |  +--templates/           - RT configuration template files.
     |  +--various/                - Various portable support files.
     +--test/                      - Kernel test suite source code.
     |  +--lib/                    - Portable test engine.
     |  +--hal/                    - HAL test suites.
     |  |  +--testbuild/           - HAL build test and MISRA check.
     |  +--nil/                    - NIL test suites.
     |  |  +--testbuild/           - NIL build test and MISRA check.
     |  +--rt/                     - RT test suites.
     |  |  +--testbuild/           - RT build test and MISRA check.
     |  |  +--coverage/            - RT code coverage project.
     +--testex/                    - EX integration test demos.
     +--testhal/                   - HAL integration test demos.
   
   ```

2. 开始移植，首先在 `demos` 文件夹下找是否有类似类型的板级例程。如果有相应的板级例程，可以直接用例程移植。

3. 建立工程，工程结构如下：

   ```
   --{root}                       
     +--main.c                 	
     +--Makefile         
     +--Chibios                	- Chibios 源码
     +--cfg                     	- 配置文件
     |  +--halconf.h				- HAL 硬件抽象层相关配置
     |  +--chconf.h				- RTOS 相关配置
     |  +--mcuconf.h				- 芯片引脚和时钟树配置
   ```

4. 对源码进行裁剪：

   - Chibios 保留 `tools` （用于编译）和 `os`（核心源码）文件夹；

   - `os` 文件夹保留 `common` (公用组件)，`hal`（HAL硬件抽象层），`license`（许可证），`oslib`，`rt`（或者NIL，选择一种 RTOS），`various`。

   - `common` 文件夹保留 `ext`（扩展组件），`include`，`lib`，`oop`，`portability`，`ports`，`startup`，`utils`。

     - `ext` 保留 `ARM` 和 `ST` 文件夹，`ARM` 文件夹内保留 `CMSIS/Core`，`ST` 文件夹内保留芯片对应的文件夹。
     - `portability` 保留 `GCC` 。
     - `ports` 保留 `ARM-common` （ARM 公用接口），`ARMv7-M`（或者其他）。
     - `startup` 保留 `ARMCMx`。其内的 `devices` 保留对应芯片的文件夹，`compliers` 保留 `GCC`。

   - `hal` 文件夹删去 `dox` 和 `template`。

     - `boards` 文件夹：

       对于已经有对应 MCU 的文件夹，可以直接保留。

       如果不存在，首先新建文件夹，找到相似的 MCU，复制其 `board.c`，`board.h` 和 `board.mk` 文件。随后根据自身 MCU 对这些文件进行修正。

       > 可以使用 STM32CubeMX 进行辅助引脚对应。

     - `osal` 文件夹：

       保留 `lib` 文件夹，剩余三个文件夹 `os-less`（无 RTOS），`rt-nil`（有 RTOS），`sb`（沙箱）按需选择。

     - `ports` 文件夹：

       保留 `common` 和 `STM32`。`STM32` 保留 `LLD` 和对应芯片 MCU 的文件夹。

   - 剩余文件夹不变。

5. 编写配置文件：

   - `chconf.h`

     ChibiOS 内核带有默认设置，适用于大多数基本应用程序。但是，在某些情况下可能需要微调 RTOS 的行为以更好地满足项目要求。在 `chconf.h` 文件内可以找到与内核相关的所有配置选项。

     此文件允许自定义调度算法、内存管理以及系统的其他选项。它还包含预处理器开关，用于启用各种功能，例如互斥、信号量、管道和内存池。这些功能默认启用，但在某些情况下，例如当您需要减少内存占用时，可能需要禁用它们。

   - `halconf.h`

     ChibiOS 的硬件抽象层包含各种驱动程序和大量代码库，但这些代码库不一定必须包含在最终固件中。根据具体应用，用户可能需要启用或禁用某些驱动程序或更改其设置。`halconf.h` 是 HAL 驱动程序的所有配置选项所在的位置。

     该文件开头包含每个驱动程序的预处理器开关，按字母顺序排列。接下来是每个驱动程序的一个部分，其中包含编译时设置。一般来说，每次用户想要启用或禁用外设时，都需要修改此文件。

     值得注意的是，ChibiOS 的 HAL 被设计为模块化，因此用户可以只包含特定应用程序所需的驱动程序，并排除不需要的驱动程序。这可以减少最终固件的内存占用，并使开发过程更加高效。

     此外，该文件还包含配置驱动程序行为的选项，例如内部缓冲区的大小、串行驱动程序的默认波特率等。`halconf.h` 文件设计为用户友好型，方便开发人员快速找到需要更改的设置。

   - `mcuconf.h`

     与 HAL 相关的许多配置高度依赖于所使用的特定微控制器。例如，在 `halconf.h` 中启用驱动程序时，外设实例的数量取决于所使用的微控制器。同样，时钟配置或中断优先级也高度依赖于硬件。所有这些配置都包含在文件中 `mcuconf.h`，即使它们属于同一系列，不同的微控制器也可能存在差异。

     `mcuconf.h`包含正确配置微控制器所需的所有底层配置。它包含配置时钟树、中断优先级、引脚分配和其他微控制器特定参数的定义。

6. 编写 `Makefile`：

   ```makefile
   ##############################################################################
   # Build global options
   # NOTE: Can be overridden externally.
   #
   
   # Compiler options here.
   ifeq ($(USE_OPT),)
     USE_OPT = -O2 -ggdb -fomit-frame-pointer -falign-functions=16
   endif
   
   # C specific options here (added to USE_OPT).
   ifeq ($(USE_COPT),)
     USE_COPT = 
   endif
   
   # C++ specific options here (added to USE_OPT).
   ifeq ($(USE_CPPOPT),)
     USE_CPPOPT = -fno-rtti
   endif
   
   # Enable this if you want the linker to remove unused code and data.
   ifeq ($(USE_LINK_GC),)
     USE_LINK_GC = yes
   endif
   
   # Linker extra options here.
   ifeq ($(USE_LDOPT),)
     USE_LDOPT = 
   endif
   
   # Enable this if you want link time optimizations (LTO).
   ifeq ($(USE_LTO),)
     USE_LTO = yes
   endif
   
   # Enable this if you want to see the full log while compiling.
   ifeq ($(USE_VERBOSE_COMPILE),)
     USE_VERBOSE_COMPILE = no
   endif
   
   # If enabled, this option makes the build process faster by not compiling
   # modules not used in the current configuration.
   ifeq ($(USE_SMART_BUILD),)
     USE_SMART_BUILD = yes
   endif
   
   #
   # Build global options
   ##############################################################################
   
   ##############################################################################
   # Architecture or project specific options
   #
   
   # Stack size to be allocated to the Cortex-M process stack. This stack is
   # the stack used by the main() thread.
   ifeq ($(USE_PROCESS_STACKSIZE),)
     USE_PROCESS_STACKSIZE = 0x400
   endif
   
   # Stack size to the allocated to the Cortex-M main/exceptions stack. This
   # stack is used for processing interrupts and exceptions.
   ifeq ($(USE_EXCEPTIONS_STACKSIZE),)
     USE_EXCEPTIONS_STACKSIZE = 0x400
   endif
   
   # Enables the use of FPU (no, softfp, hard).
   ifeq ($(USE_FPU),)
     USE_FPU = no
   endif
   
   # FPU-related options.
   ifeq ($(USE_FPU_OPT),)
     USE_FPU_OPT = -mfloat-abi=$(USE_FPU) -mfpu=fpv4-sp-d16
   endif
   
   #
   # Architecture or project specific options
   ##############################################################################
   
   ##############################################################################
   # Project, target, sources and paths
   #
   
   # Define project name here
   PROJECT = ch
   
   # Target settings.(目标核心类型)
   MCU  = cortex-m3
   
   # Imported source files and paths.(文件夹位置)
   CHIBIOS  := ./Chibios
   CONFDIR  := ./cfg
   BUILDDIR := ./build
   DEPDIR   := ./.dep
   
   # Licensing files.(许可证文件)
   include $(CHIBIOS)/os/license/license.mk
   # Startup files.(启动文件)
   include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/startup_stm32f1xx.mk
   # HAL-OSAL files (optional).(硬件抽象层文件)
   include $(CHIBIOS)/os/hal/hal.mk							# HAL 
   include $(CHIBIOS)/os/hal/ports/STM32/STM32F1xx/platform.mk # 编译器接口
   include $(CHIBIOS)/os/hal/boards/STM32F103C8T6/board.mk     # 板级接口
   include $(CHIBIOS)/os/hal/osal/rt-nil/osal.mk				# RTOS 接口
   # RTOS files (optional).(RTOS文件)
   include $(CHIBIOS)/os/rt/rt.mk											# RTOS 
   include $(CHIBIOS)/os/common/ports/ARMv7-M/compilers/GCC/mk/port.mk		# 编译器接口
   # Auto-build files in ./source recursively.
   include $(CHIBIOS)/tools/mk/autobuild.mk								# 编译工具
   # Other files (optional).
   
   # Define linker script file here
   LDSCRIPT= $(STARTUPLD)/STM32F103x8.ld									# 链接文件
   
   # C sources that can be compiled in ARM or THUMB mode depending on the global
   # setting.	# C源文件
   CSRC = $(ALLCSRC) \
          main.c
   
   # C++ sources that can be compiled in ARM or THUMB mode depending on the global
   # setting.
   CPPSRC = $(ALLCPPSRC)
   
   # List ASM source files here.
   ASMSRC = $(ALLASMSRC)
   
   # List ASM with preprocessor source files here.
   ASMXSRC = $(ALLXASMSRC)
   
   # Inclusion directories.
   INCDIR = $(CONFDIR) $(ALLINC) $(TESTINC)
   
   # Define C warning options here.
   CWARN = -Wall -Wextra -Wundef -Wstrict-prototypes
   
   # Define C++ warning options here.
   CPPWARN = -Wall -Wextra -Wundef
   
   #
   # Project, target, sources and paths
   ##############################################################################
   
   ##############################################################################
   # Start of user section
   #
   
   # List all user C define here, like -D_DEBUG=1
   UDEFS =
   
   # Define ASM defines here
   UADEFS =
   
   # List all user directories here
   UINCDIR =
   
   # List the user directory to look for the libraries here
   ULIBDIR =
   
   # List all user libraries here
   ULIBS =
   
   #
   # End of user section
   ##############################################################################
   
   ##############################################################################
   # Common rules
   #
   
   RULESPATH = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk
   include $(RULESPATH)/arm-none-eabi.mk
   include $(RULESPATH)/rules.mk
   
   #
   # Common rules
   ##############################################################################
   
   ##############################################################################
   # Custom rules
   #
   
   #
   # Custom rules
   ##############################################################################
   
   ```

7. `make` 进行编译和程序生成，使用 STM32 Utility 烧录。

