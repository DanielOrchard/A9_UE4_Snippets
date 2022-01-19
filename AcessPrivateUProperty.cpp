
// If the engine has a UProperty thats private, you can access it via the Reflection system. nice example how below:

if ( StageActor )
{
	const FObjectProperty* LevelSequenceProperty = FindFieldChecked< FObjectProperty >( AUsdStageActor::StaticClass(), FName(TEXT("LevelSequence")) );
	if ( LevelSequenceProperty )
	{
		ULevelSequence* ActorLevelSequence = Cast<ULevelSequence>( LevelSequenceProperty->GetPropertyValue_InContainer( StageActor ) );
		FPlatformMisc::LowLevelOutputDebugStringf( TEXT("ActorLevelSequence: 0x%llu\n"), ActorLevelSequence );
	}
}