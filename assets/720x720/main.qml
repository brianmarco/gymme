import bb.cascades 1.0
import bb.multimedia 1.0

TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: "Timer"
        Page {
            Container {
                layout: DockLayout {

                }
                Container {
                    id: dummyHeaderContainer
                    objectName: "dummyHeaderContainer"
                    horizontalAlignment: HorizontalAlignment.Fill
                    rightPadding: 15.0
                    topPadding: 15.0
                    leftPadding: 15.0
                    layout: DockLayout {

                    }
                    Label {
                        text: qsTr("9:00am")
                        horizontalAlignment: HorizontalAlignment.Left
                    }
                    Label {
                        text: qsTr("09:00")
                        horizontalAlignment: HorizontalAlignment.Right
                    }
                }
                Container {
                    id: dummyTimerContainer
                    objectName: "dummyTimerContainer"
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Center
                    bottomPadding: 150.0
                    Container {
                        horizontalAlignment: HorizontalAlignment.Center
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight

                        }
                        Label {
                            text: qsTr("Excerise #%1")
                        }
                        Label {
                            text: qsTr("-")
                        }
                        Label {
                            text: qsTr("Set #%1")
                        }
                    }
                    Label {
                        text: "00:00.000"
                        textStyle.fontWeight: FontWeight.Normal
                        horizontalAlignment: HorizontalAlignment.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 28.0
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "Activity"
                        textStyle.fontWeight: FontWeight.Bold
                        textStyle.fontStyle: FontStyle.Italic
                    }
                }
                Container {
                    id: headerContainer
                    objectName: "headerContainer"
                    horizontalAlignment: HorizontalAlignment.Fill
                    rightPadding: 15.0
                    topPadding: 15.0
                    leftPadding: 15.0
                    visible: false
                    layout: DockLayout {
                    
                    }
                    Label {
                        text: Qt.formatDateTime(new Date(), "h:mmap")
                        horizontalAlignment: HorizontalAlignment.Left
                    }
                    Label {
                        id: totalTimeLabel
                        text: workoutController.totalTime
                        horizontalAlignment: HorizontalAlignment.Right
                    }
                }
                Container {
                    id: timerContainer
                    objectName: "timerContainer"
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Center
                    bottomPadding: 150.0
                    visible: false
                    Container {
                        horizontalAlignment: HorizontalAlignment.Center
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        
                        }
                        Label {
                            text: qsTr("Exercise #%1").arg(workoutController.exerciseCount);
                        }
                        Label {
                            text: qsTr("-")
                        }
                        Label {
                            id: exerciseSetCountLabel
                            text: qsTr("Set #%1").arg(workoutController.exerciseSetCount);
                        }
                    }
                    Label {
                        id: timeLabel
                        text: workoutController.currentTime
                        textStyle.fontWeight: FontWeight.Normal
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 28.0
                        horizontalAlignment: HorizontalAlignment.Center
                        onCreationCompleted: {
                            workoutController.nowWastingTime.connect(timeLabel.handleWastingTime);
                        }
                        function handleWastingTime() {
                            app.playSound("warn.wav");
                            timeLabel.textStyle.color = Color.Red; 
                        }
                    }
                    Label {
                        id: bufferTimeLabel
                        text: workoutController.bufferTime
                        textStyle.fontWeight: FontWeight.Normal
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontSizeValue: 28.0
                        horizontalAlignment: HorizontalAlignment.Center
                        visible: false
                    }
                    Label {
                        id: activityLabel
                        horizontalAlignment: HorizontalAlignment.Center
                        text: qsTr("%1").arg(workoutController.currentActivity)
                        textStyle.fontWeight: FontWeight.Bold
                        textStyle.fontStyle: FontStyle.Italic
                        animations: [
                            SequentialAnimation {
                                id: pulseActivityLabel
                                repeatCount: AnimationRepeatCount.Forever
                                animations: [
                                    FadeTransition {
                                        fromOpacity: 1.0
                                        toOpacity: 0.2
                                        duration: 1000
                                    },
                                    FadeTransition {
                                        fromOpacity: 0.2
                                        toOpacity: 1.0
                                        duration: 400
                                    }
                                ]
                            }
                        ]
                    }

                }
                Container {
                    id: buttonsContainer
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Bottom

                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    
                    bottomPadding: 40.0
                    leftPadding: 5.0
                    rightPadding: 5.0
                    Button {
                        id: pauseBtn
                        text: "||"
                        enabled: false
                        onClicked: {
                            workoutController.togglePause();
                            setTimerToggleBtn.setEnabled(!setTimerToggleBtn.enabled);
                            if (workoutController.currentActivity == "Paused") {
                                setTimerToggleBtn.setEnabled(false);
                                nextSetBtn.setEnabled(false);
                            }
                            else {
                                setTimerToggleBtn.setEnabled(true);
                                if (workoutController.isActive()) {
                                    nextSetBtn.setEnabled(false);
                                }
                                else {
                                    nextSetBtn.setEnabled(true);
                                }
                            }
                        }
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 25.0
                        }
                    }
                    Button {
                        id: setTimerToggleBtn
                        text: "Start Set"
                        onClicked: {
                            pauseBtn.enabled = true;
                            if (workoutController.isActive()) {
                                restStart();
                            } else {
                                exerciseSetStart();
                            }
                        }
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 55.0
                        }
                        function exerciseSetStart() {
                            app.playSound("beep.wav");
                            
                            pulseActivityLabel.play();
                            timeLabel.textStyle.color = Color.Green;
                            workoutController.stopRest();
                            workoutController.start();
                            nextSetBtn.setEnabled(false);
                            setTimerToggleBtn.setText("Finish Set");
                        }
                        function restStart() {
                            app.playSound("beep.wav");
                            
                            workoutController.stop();
                            workoutController.startRest();
                            timeLabel.textStyle.color = Color.Blue;
                            nextSetBtn.setEnabled(true);
                            setTimerToggleBtn.setText("Start Set");
                        }
                    }
                    Button {
                        id: nextSetBtn
                        text: ">>"
                        enabled: false
                        onClicked: {
                            workoutController.nextExercise();
                        }
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 20.0
                        }
                    }

                }
            }
        }
    }
    Tab {
        title: "Sets"
        Page {
            Container {
                Label {
                    text: qsTr("Second tab") + Retranslate.onLocaleOrLanguageChanged
                }
            }
        }
    }
}