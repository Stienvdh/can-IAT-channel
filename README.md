# A packet inter-arrival-time channel for Sancus-enabled MSP430 CAN nodes

## Structure

 - **/sender/** holds sender-side timing channel logic
 - **/receiver/** holds receiver-side timing channel logic, and channel performance bookkeeping 
 - **/can-interrupt/** holds CAN message arrival interrupt configuration for MSP430 hardware paired with a MCP2515 CAN controller

## Setup

1. Get the Sancus toolchain [here](https://github.com/sancus-tee/sancus-main)  
        ***NOTE**: Make sure to use 128 bit security*

3. Clone this repository:
```bash
$ git clone https://github.com/Stienvdh/can-IAT-channel.git
$ git submodule init
$ git submodule update
```

## Use

### Connecting and monitoring your CAN nodes

0. **Required hardware**: 2 FPGAs, each synthesised with a Sancus-enabled [OpenMSP430 core](https://github.com/sancus-tee/tutorial-dsn18/blob/master/app/sancus/sancus-core-128bit-irq-pm1spi-pm2uart-pm3p3-hatp1.mcs) and attached to a MCP2515 CAN controller. Both should be connected to the same CAN bus, and have a line attached to their CAN controller interrupt pin, as shown below.

![Hardware setup](https://github.com/Stienvdh/can-IAT-channel/blob/master/hardware-setup.png)

1. Attach the two FPGAs to your PC by plugging in their UART USB lines in the following order:  
        ***NOTE**: FPGA 1 will function as a receiver, FPGA2 as a sender*  
  
    - FPGA 1, uplink
    - FPGA 1, downlink
    - FPGA 2, uplink
    - FPGA 2, downlink

2. Monitor FPGA debug output at a 115200 baudrate:  
        ***NOTE**: Make sure to issue these commands in their own separate terminals*
```bash
$ screen /dev/ttyUSB1 115200 # replace 'USB1' with your receiver downlink UART device
```

```bash
$ screen /dev/ttyUSB3 115200 # replace 'USB3' with your sender downlink UART device
```

### Running a timing channel demo

1. Set up the receiver:
```bash
$ cd receiver
$ make load
```
2. Set up the sender:
```bash
$ cd sender
$ make load
```
3. Monitor progress over `/dev/ttyUSB1` (*receiver downlink*) and `/dev/ttyUSB3`(*sender downlink*)

