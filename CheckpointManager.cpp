#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint* cp) 
{
    if (cp == nullptr) 
    {
        return;
    }
    history.push_back(cp);
}

RunCheckpoint* CheckpointManager::undo() 
{
    if (history.empty()) 
    {
        return nullptr;
    }
    RunCheckpoint* cp = history.back();
    history.pop_back();
    return cp;
}

CheckpointManager::~CheckpointManager() 
{
    for (size_t i = 0; i < history.size(); i++) 
    {
        delete history[i];
    }
}