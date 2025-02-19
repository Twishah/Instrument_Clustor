import QtQuick 2.6

Image {

    property var value; // 2-bit-value for the indicator: 0: Indicator off
    property var valueBackup;
    property bool canError: false
    property string sourceBackup: source

    fillMode: Image.PreserveAspectFit


    function vIndicatorOn() {
        opacity = 1.0
    }

    function vIndicatorOff() {
        opacity = 0.0
    }

    function vSymbolToggle() {
        if (blinkingPictoIsVisible === true) {
            vIndicatorOn()
        }
        else {
            vIndicatorOff()
        }
    }

    function vSymbolToggleFast() {
//        if (bToggleSignal2Hz === true) {
//            vIndicatorOn()
//        }
//        else {
//            vIndicatorOff()
//        }
    }

    function vSymbolHide() {
        opacity = 0.0
    }


    function vIndicatorControl() {

        if(canError)
        {
            value = 2
            source = source
       }
        else if (value === 3) {
            value = valueBackup;
            source = source;
        }
        else {
            valueBackup = value;
            sourceBackup = source;
        }

        //opacity = ((value === 1) || ((value === 2 || canError) && (blinkingPictoIsVisible === true))) ? 1.0 : 0.0

        if (value === 3) {
            // no change
        }
        else if (value === 2 || canError) {
            if (blinkingPictoIsVisible === true) {
                opacity = 1.0
            }
            else {
                opacity = 0.0
            }
        }
        else if (value === 1) {
            opacity = 1.0
        }
        else if (value === 0) {
            opacity = 0.0
        }
        else {
            //vSymbolToggleFast()
        }
    }

    Timer {
        running: true
        repeat: true
        interval: 200
        onTriggered:{vIndicatorControl()}
    }
}
