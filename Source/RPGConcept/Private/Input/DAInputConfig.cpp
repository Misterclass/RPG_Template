// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Input/DAInputConfig.h"
#include "InputAction.h"


UInputAction* UDAInputConfig::FindActionByTag(const FGameplayTag& InputTag) const
{
    for (const FRpgInputTagAction& InputTagAction : InputTagActions)
    {
        if (InputTag == InputTagAction.InputTag)
        {
            return InputTagAction.InputAction;
        }
    }

    return nullptr;
}
