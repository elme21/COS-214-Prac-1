#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "PostgresFactory.h"
#include "BatchPipeline.h"
#include "CheckpointManager.h"
#include "RunCheckpoint.h"

int main() {
    
    TransformationRegistry registry;
    registry.registerStep("dedup", new DeduplicateStep());
    registry.registerStep("aggregate", new AggregateByRegionStep());

    
    BatchPipeline pipeline(new PostgresFactory());

    
    pipeline.addStep(registry.create("dedup"));
    pipeline.addStep(registry.create("aggregate"));

    
    CheckpointManager manager;

    pipeline.run();
    RunCheckpoint* cp = pipeline.createCheckpoint();
    manager.save(cp);

    
    return 0;
}