#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

    FVector LocSum = { 0, 0, 0 };
    int totalEvent = 0;

    // --- 컴포넌트 ---
    UPROPERTY(VisibleAnywhere, Category = "MySettings")
    UStaticMeshComponent* Mesh;

    // --- 타이머 관련 변수 ---
    FTimerHandle MemberTimerHandle;
    int32 CurrentCount = 0;

    // --- 함수 선언 ---
    void Move();
    void Turn();
    void TriggerEvent();

    // 타이머로 실행할 함수
    void ExecuteStep();
};