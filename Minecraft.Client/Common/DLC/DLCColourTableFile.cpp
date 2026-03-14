#include "DLCColourTableFile.h"
#include "..\..\Minecraft.h"
#include "..\..\TexturePack.h"
#include "..\..\TexturePackRepository.h"
#include "DLCManager.h"
#include "stdafx.h"

DLCColourTableFile::DLCColourTableFile(const wstring &path) : DLCFile(DLCManager::e_DLCType_ColourTable, path)
{
    m_colourTable = nullptr;
}

DLCColourTableFile::~DLCColourTableFile()
{
    if (m_colourTable != nullptr)
    {
        app.DebugPrintf("Deleting DLCColourTableFile data\n");
        delete m_colourTable;
    }
}

void DLCColourTableFile::addData(PBYTE pbData, DWORD dwBytes)
{
    ColourTable *defaultColourTable = Minecraft::GetInstance()->skins->getDefault()->getColourTable();
    m_colourTable = new ColourTable(defaultColourTable, pbData, dwBytes);
}
