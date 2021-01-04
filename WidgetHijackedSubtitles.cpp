// Amazing trick to highjack the built in subtitle system, and route the result to UMG
// This lets you continue to use the standard workflows, but beautify it with UMG. (So still DialogueWave, SpokenWord/Subtitle option in SoundSource), and still "PlayDialogue"
// You are limited to what the core system does in terms of text, this is only to alter the final rendering.
// Note - This is, I believe, how Fortnite works
// Note 2 - This example uses TextBlock, but could be done with RichText for far cooler effects (my next goal)
// Note 3 - Iv not unbound or done any safety here, this is the rawest, simpliest version of this.
// Note 4 - This delegate is marked as "HACK", so it may change.
// Credit - Will add when I find it again. (Unreal forum, James Dale, subtitle search, page 2, 2019)


// .h file
UCLASS()
class COSMOS_API USubtitleContainer : public UTextBlock
{
	GENERATED_BODY()

public:

	USubtitleContainer();

	void OnSubtitleRequested(const FText& InText);
}

// .CPP
#include <SubtitleManager.h>
USubtitleContainer::USubtitleContainer()
{
	FSubtitleManager::GetSubtitleManager()->OnSetSubtitleText().AddUObject(this, &USubtitleContainer::OnSubtitleRequested);
}

void USubtitleContainer::OnSubtitleRequested(const FText& InText)
{
	SetText(InText);
}