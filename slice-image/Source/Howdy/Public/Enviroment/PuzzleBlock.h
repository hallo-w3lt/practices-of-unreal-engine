/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PuzzleBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDraggingSignature, bool, bDragging);

USTRUCT()
struct FMaterialParametersStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
		int32 U{ 1 };
	UPROPERTY()
		int32 V{ 1 };
	UPROPERTY()
		int32 Size{ 4 };
	UPROPERTY()
		int32 Saturation{ 0 };
};

UCLASS()
class HOWDY_API APuzzleBlock : public AActor
{
	GENERATED_BODY()

public:
	explicit APuzzleBlock(const FObjectInitializer& ObjectInitializer);
	virtual ~APuzzleBlock() {};

	FOnDraggingSignature OnDragging;

	// virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	// virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	virtual void BeginPlay() override;

	/*UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);*/

public:
	virtual void Tick(float InDeltaTime) override;

	void HandleClicked();

	UFUNCTION()
		void OnClickedBlock(UPrimitiveComponent* ClickedComponent, FKey ButtonClicked);
	UFUNCTION()
		void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);
	UFUNCTION()
		void SetOwningGrid(class APuzzleGrid* InPuzzleBlockGrid);
	UFUNCTION()
		void SetMaterialParameter(const FMaterialParametersStruct& InValue);

private:
	UPROPERTY()
		class AHowdyGameMode* HowdyGameMode{ nullptr };

	UPROPERTY()
		class AHowdyGameState* HowdyGameState{ nullptr };

	UPROPERTY()
		class UMaterialInstanceDynamic* PuzzleMaterialInstanceDynamic{ nullptr };
	UPROPERTY()
		class UMaterialInstance* PuzzleMaterialInstance = nullptr;

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* SceneComponent{ nullptr };

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PlaneMesh{ nullptr };

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* BodyMesh{ nullptr };

	UPROPERTY()
		class ACameraActor* CameraActor{ nullptr };

	UPROPERTY(Category = Behaviour, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float ScopeCamera{ 200.f };

	UPROPERTY()
		class AHowdyPlayerController* PlayerController{ nullptr };

	UPROPERTY()
		class APuzzleBlock* PuzzleBlockOverlapped{ nullptr };

	UPROPERTY()
		class APuzzleGrid* OwningGrid{ nullptr };

	UPROPERTY()
		class AGameHUD* HUD{ nullptr };

	FVector OriginLocation{ FVector::ZeroVector };

	bool bCanDragging{ false };
	bool bDragging{ false };
	bool bOverlapped{ false };
	bool bHitting{ false };

	FMaterialParametersStruct MaterialParameter;
	struct FHitResult OutHit;

	int32 Index{ 0 };

public:
	FORCEINLINE class USceneComponent* GetMainComponent() const { return SceneComponent; }

	FORCEINLINE class UStaticMeshComponent* GetPlaneMesh() const { return PlaneMesh; }
	FORCEINLINE class UStaticMeshComponent* GetBodyMesh() const { return BodyMesh; }

	FORCEINLINE class UMaterialInstanceDynamic* GetMaterialInstanceDynamic() const { return PuzzleMaterialInstanceDynamic; }
	FORCEINLINE FMaterialParametersStruct GetMaterialParameter() const { return MaterialParameter; }

	FORCEINLINE int32 GetIndex() const { return Index; }
	FORCEINLINE FVector GetOriginLocation() const { return OriginLocation; }

	FORCEINLINE APuzzleGrid* GetOwningGrid() const { return OwningGrid; }
	FORCEINLINE void SetCanDragging(const bool InValue) { bCanDragging = InValue; }

	FORCEINLINE void SetCamera(class ACameraActor* InValue) { CameraActor = InValue; }
	FORCEINLINE void SetIndex(const int32 InValue) { Index = InValue; }
};
