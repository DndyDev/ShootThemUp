// Shoot Them Up game.All Right Reserved


#include "Components/STUCharacterMovementComponent.h"

#include "STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    return Player && Player->isRunnig() ? MaxSpeed * RunModifier : MaxSpeed;
    
}
