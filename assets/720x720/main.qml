import bb.cascades 1.0

TabbedPane {
    showTabsOnActionBar: true
    
    Tab {
        title: "Timer"
        imageSource: "asset:///icons/icon_117.png"
        Page {
            content: WorkoutTimerView {
                isUsingDarkTheme: app.isUsingDarkTheme();
            }
            actions: [
                ActionItem {
                    title: "Edit"
                    imageSource: "asset:///icons/ic_edit.png"
                },
                ActionItem {
                    title: "Finish Workout"
                    imageSource: "asset:///icons/icon_153.png"
                }
            ]
        }
    }
    Tab {
        title: "Workouts"
        imageSource: "asset:///icons/ic_view_list.png"
        Page {
            content: WorkoutsView {
                
            }
        }
    }
}