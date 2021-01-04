// Use UMG Widgets inside slate, much less painful than writing slate when you just need a quick job (though EditorWidgets sort of negate this need)
// Credit - https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1644199-using-a-umg-widget-in-slate

void CreateWindowFromUMG(UWidgetBlueprint* Blueprint)
{
    if (!Blueprint) return;

    //~ Gets actual widget class from the blueprint
    TSubclassOf<UEditorUtilityWidget> WidgetClass = Blueprint->GeneratedClass;

    //~ We need da world
    UWorld* World = GEditor->GetEditorWorldContext().World();
    check(World);

    //~ Create widget 
    UEditorUtilityWidget* CreatedUMGWidget = CreateWidget<UEditorUtilityWidget>(World, WidgetClass);
    if (CreatedUMGWidget)
    {

        //~ Create Slate window
        TSharedPtr<SWindow> EditorTab = SNew(SWindow)
            .AutoCenter(EAutoCenter::None)
            .Title(FText::FromString("my win"))
            .IsInitiallyMaximized(false)
            .ClientSize(FVector2D(300,300))
            .SizingRule(ESizingRule::UserSized)
            .SupportsMaximize(true)
            .SupportsMinimize(true)
            .CreateTitleBar(true)
            .HasCloseButton(true);

        //~ Add Windows to slate app
        FSlateApplication & SlateApp = FSlateApplication::Get();
        SlateApp.AddWindow(EditorTab.ToSharedRef(), true);

        //~ Use UMG in slate
        EditorTab->SetContent(CreatedUMGWidget->TakeWidget());
    }
}