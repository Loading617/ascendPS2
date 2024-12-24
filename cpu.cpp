#include <iostream>
#include <cstdint>

// Simplified structure for PS2's MIPS R5900 CPU
class EmotionEngine {
public:
    uint32_t registers[32] = {0}; // General-purpose registers
    uint32_t pc = 0xBFC00000;     // Program Counter (default boot address)

    void executeInstruction(uint32_t instruction) {
        // Decode instruction (simplified)
        uint8_t opcode = (instruction >> 26) & 0x3F;
        switch (opcode) {
            case 0x00: // Example: ADD
                addInstruction(instruction);
                break;
            default:
                std::cout << "Unknown opcode: " << std::hex << (int)opcode << "\n";
        }
    }

private:
    void addInstruction(uint32_t instruction) {
        uint8_t rd = (instruction >> 11) & 0x1F;
        uint8_t rs = (instruction >> 21) & 0x1F;
        uint8_t rt = (instruction >> 16) & 0x1F;
        registers[rd] = registers[rs] + registers[rt];
        pc += 4; // Advance to next instruction
    }
};

int main() {
    EmotionEngine ee;
    uint32_t instruction = 0x00221820; // Example ADD instruction
    ee.executeInstruction(instruction);
    return 0;
}
