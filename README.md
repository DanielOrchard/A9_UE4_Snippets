# A9_UE4_Snippets
Random Cool snippets of code for Unreal that are somewhat obscure, but cool results

## SpawnEventsInNewBlueprints
Shows how to register events into the blueprint factory, so that when you make a new blueprint of X subclass, it auto adds the events, much like how all actor blueprints have "begin play", and "event tick" by default, this lets you add your own
NB. I found this online, but I don't recall where, so no credit for me here.

## Widgets inside slate
I have not tested this, but looks somewhat useful. EditorWidgets have mostly replaced the need for this, but there may still be times when its useful

## Subtitle Hijacker
This is a really cool snippet of code that hooks into the FSubtitleManager, and pulls the subtitles out of it and into a widget. This both stops the built-in renderer (thanks epic for making that out the box), and instead feeds the result into a UMG Widget. Add a SubtitleContainer to your project and done, subs.
I will be expanding this myself to see about RichText, and accessing the text in BP before sending to the display, so we could handle colours and fx. 
This still uses the built in system, its only a renderer override, so your still limited by the core system, but thats out the box, no workflow changes, so I prefer this to a totally custom solution as seen on the marketplace. I also suspect this may get overhauled soon-ish, so this may be depreciated by UE5.