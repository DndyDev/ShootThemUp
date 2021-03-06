// Shoot Them Up game.All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "STUHealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USTUHealthComponent;
class UTextRenderComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    // Sets default values for this character's properties
    ASTUBaseCharacter(const FObjectInitializer& ObjInit);

    

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent *SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent *CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTUHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent* HealthTextComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animations")
    UAnimMontage* DeathAnimMontage;


    UPROPERTY(EditDefaultsOnly, Category="Damage")
    float LifeSpanOnDeath = 5.0f;
    
    UPROPERTY(EditDefaultsOnly, Category="Damage")
        FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);

    UPROPERTY(EditDefaultsOnly, Category="Damage")
    FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

  
    virtual void BeginPlay() override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category="Movement")
    bool isRunnig() const;

    UFUNCTION(BlueprintCallable, Category="Movement")
    float GetMovementDirection() const;

    private:

    bool bRunning = false;
    bool IsMovingForward;
    
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    
    void Run();
    void RunOut();

    void OnDeath();
    void OnHealthChanged(float Health);

    UFUNCTION()
    void OnGroundLanded(const FHitResult& Hit);
};
