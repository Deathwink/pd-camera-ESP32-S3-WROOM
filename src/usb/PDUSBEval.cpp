#include "PDUSBEval.h"
#include <string.h>
#include <stdio.h>

///
static USBSerialHost& host = USBSerialHost::GetInstance();

///
PDUSBEval::PDUSBEval(size_t sizeExpression)
{
    char strCommand[32];
    snprintf(strCommand, sizeof(strCommand), "eval %zu\n", sizeExpression);
    m_sizeCommand = strlen(strCommand);

    m_buffer.resize(m_sizeCommand + sizeExpression);
    ::memcpy(m_buffer.data(), strCommand, m_sizeCommand);
}

///
uint8_t* PDUSBEval::GetExpressionBuffer()
{
    if (m_buffer.empty())
    {
        return NULL;
    }

    return m_buffer.data() + m_sizeCommand;
}

///
#define EVAL_WAIT_MSEC 10 * 1000
bool PDUSBEval::Eval()
{
    if (m_buffer.empty())
    {
        return false;
    }

    return host.Write(m_buffer.data(), m_buffer.size(), EVAL_WAIT_MSEC);
}

/*
    長さを指定して文字列の命令コードを生成します。
    利用する際には、命令コードの後に、文字列データを付与する必要があります。

    opecode :
        0 - 0x28    : 0x04  (short string)
        0x29 -      : 0x14  (long string)

    operand :
        // If byte1 is 0x0, only byte2
        byte1 : length / 0x7f
        byte2 : length - (byte1 * 0x80) + 0x81
*/
void PDUSBEval::MakeLuaStringInstruction(size_t length, std::vector<uint8_t>& instruction)
{
    // opecode
    if (length <= 0x28)
    {
        instruction.push_back(0x04);
    }
    else
    {
        instruction.push_back(0x14);
    }

    // operand
    int byte1 = length / 0x7f;
    int byte2 = length - (byte1 * 0x80) + 0x81;

    if (byte1 != 0)
    {
        instruction.push_back(byte1);
    }
    instruction.push_back(byte2);
}


