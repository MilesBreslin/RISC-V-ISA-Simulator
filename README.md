# RISC-V ISA Simulator

![Compile Test](https://github.com/MilesBreslin/RISC-V-ISA-Simulator/workflows/Compile%20Test/badge.svg)

This is a project for Portland State University's Computer Architecture course. Using a ascii memory image, this will simulate a RISC-V processor. This implements most of the rv32i base instruction set.

### Design

Our team was tasked with the design and build of a RISC-V Instruction Set Architecture (ISA) simulator. We chose to implement the design in C and utilize git for our version control and the GitHub Actions to assist in automated testing. Instruction decoding is handled via a code generation tool we wrote. This allows for easy manipulation of parameters and reconfiguring or addition of instruction and function type definitions which would make porting to another RISC architecture such as RISC64 effortless. It also made adding the `M` extension, `ECALL` and Interactive mode functionality to our project nearly effortless.

##### Memory Images

The RISC-V simulator takes a memory image file that holds memory values of specified addresses in hexadecimal. In addition, our format allows for setting register states and the program counter, which completes the simulator state. The format of the memory image file is a list of addresses and values. For each line, an address is specified, followed by the value. White space is ignored.

```yaml
0: fd010113
4: 02812623
8: 03010413
c: fca42e23
REG_T3: FF
```

### Building

There are no dependencies for this outside of glibc. To build the executable, run `make`. The simulator will be accessible in `build/riscv_simulator`. Use the `--help` flag to see usage information.

##### Developing

Many of the tools depend on other applications outside of our project. You may need the RISC-V GNU Toolchain for Linux executables and `ELF` executable, `yq`, `bash` and `coreutils`, depending on the tool you are using.

The `opcodes.yaml` file is not a part of the build process. Instead, it is requires the development tool `tools/opcode_generator` to generate both `src/instructions.c` and `src/instructions.h`.

##### Testing

The end-to-end tests require both a `.mem` file and a `.check` file. A `.check` file is the same as a `.mem` file, all lines used in the check file must be contained in a complete memory, register, and program counter dump from the execution of the memory image file.

### Support

This project will enter an abandoned state effective March 21, 2021. No new features or bug fixes are planned prior to that date. This will serve as an educational reference only.

This application is released under the MIT License. See the [LICENSE](./LICENSE) file for more details.