#include "LightSwitch.h"

#include "Components/LightComponent.h"

ALightSwitch::ALightSwitch()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void ALightSwitch::Interact()
{
	if (Light)
	{
		auto comp = Light->FindComponentByClass<ULightComponent>();
		if (comp)
		{
			comp->SetVisibility(!comp->IsVisible());
		}
	}
}
