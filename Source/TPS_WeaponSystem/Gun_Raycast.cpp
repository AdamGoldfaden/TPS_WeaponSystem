#include "Gun_Raycast.h"
#include "DrawDebugHelpers.h"

void AGun_Raycast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun_Raycast::StartShooting()
{
	UE_LOG(LogTemp, Warning, TEXT("Got here"));
	FHitResult OutHit;
	if (GunTrace(OutHit))
	{
		FVector StartLocation = GetGunMesh()->GetSocketLocation(TEXT("MuzzleSocket"));
		FVector Direction = GetDirectionFromStartToHit(StartLocation, OutHit);
		FVector EndLocation = StartLocation + (MaxRange * Direction) + GetOwner()->GetVelocity();
		DrawDebugPoint(GetWorld(), OutHit.Location, 10.f, FColor::Red, false, 0.25f);
	}
}