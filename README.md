# APM32E103 GPIO 模拟 I²C 示例 / APM32E103 GPIO-Emulated I²C Example

[中文](#中文说明) | [English](#english)

## 中文说明

本项目演示如何在 APM32E103 MCU 上使用 GPIO 模拟 I²C 通信，适用于没有使用硬件 I²C 外设或需要自定义时序的应用场景。

### 主要功能

- 通过 GPIO 实现软件 I²C 主机通信
- 支持主机发送与接收
- 支持存储器写入与读取测试
- 对发送和接收数据进行比较
- 使用 LED 指示测试结果或错误状态

### 开发环境

- 目标板：APM32E103 MINI
- 工程：Keil MDK-ARM（`.uvprojx`）
- 示例版本：V1.0.0
- 主要文件：
  - `src/main.c`
  - `src/soft_i2c.c`
  - `inc/soft_i2c.h`

### 使用方法

1. 打开目录中的 MDK 工程。
2. 根据实际硬件检查 `soft_i2c.c` 中的 GPIO 与时序配置。
3. 连接目标 I²C 器件，并确认器件地址和供电电压。
4. 编译并下载程序至 APM32E103 MINI。
5. 观察 LED 状态，或通过调试器检查发送和接收缓冲区。

默认示例使用地址 `0xA0` 进行数据收发测试。请根据目标器件的数据手册修改地址及读写流程。

### 注意事项

软件 I²C 的通信速率和可靠性会受到系统时钟、GPIO 配置、延时函数及上拉电阻影响。连接外部器件前，请确认总线电压与 MCU IO 电平兼容。

### 技术支持

更多产品资料与技术支持请访问：[www.geehy.com](https://www.geehy.com/)。

---

## English

This project demonstrates GPIO-emulated I²C communication on an APM32E103 MCU. It is intended for applications that do not use the hardware I²C peripheral or require custom bus timing.

### Features

- Software I²C master implemented with GPIO
- Master transmit and receive operations
- Memory write and read test modes
- Transmit/receive buffer comparison
- LED indication for test results and error states

### Development environment

- Target board: APM32E103 MINI
- Project: Keil MDK-ARM (`.uvprojx`)
- Example version: V1.0.0
- Main files:
  - `src/main.c`
  - `src/soft_i2c.c`
  - `inc/soft_i2c.h`

### Usage

1. Open the MDK project included in the example directory.
2. Check the GPIO and timing configuration in `soft_i2c.c`.
3. Connect the target I²C device and verify its address and supply voltage.
4. Build and program the example to the APM32E103 MINI.
5. Observe the LEDs or inspect the transmit and receive buffers with a debugger.

The default example uses address `0xA0` for its transfer test. Update the address and transaction sequence according to the target device datasheet.

### Notes

Software I²C speed and reliability depend on the system clock, GPIO configuration, delay implementation, and pull-up resistors. Verify bus-voltage compatibility before connecting an external device.

### Support

For product information and technical support, visit [www.geehy.com](https://www.geehy.com/).
