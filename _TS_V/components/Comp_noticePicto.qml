import QtQuick 2.6
import QtGraphicalEffects 1.0

Image {

	fillMode: Image.Pad
	source: ""

	property int nbSignal: 1; // at the moment maximum 4

	property int signal1: 0;
	property int signal1Value: 0;
	property string signal1Source: "";
	property int signal1canError: 0;
	property string signal1SourceAt0: "";

	property int signal2: 0;
	property int signal2Value: 0;
	property string signal2Source: "";
	property int signal2canError: 0;

	property int signal3 : 0;
	property int signal3Value : 0;
	property string signal3Source: "";
	property int signal3canError: 0;

	property int signal4 : 0;
	property int signal4Value : 0;
	property string signal4Source: "";
	property int signal4canError: 0;

	property bool noBlink: false

	function updateValues()
	{
		if (signal1 !== 3)
		{
			signal1Value = signal1
		}
		if (nbSignal > 1 && signal2 !== 3)
		{
			signal2Value = signal2
		}

		if (nbSignal > 2 && signal3 !== 3)
		{
			signal3Value = signal3
		}

		if (nbSignal > 3 && signal4 !== 3)
		{
			signal4Value = signal4
		}
	}

	function updateSource()
	{
		if (signal1canError)
		{
			source = signal1Source
		}
		else if (nbSignal > 1 && signal2canError)
		{
			source = signal2Source
		}
		else if (nbSignal > 2 && signal3canError)
		{
			source = signal3Source
		}
		else if (nbSignal > 3 && signal4canError)
		{
			source = signal4Source
		}
		else if (signal1Value)
		{
			source = signal1Source
		}
		else if (nbSignal > 1 && signal2Value)
		{
			source = signal2Source
		}
		else if (nbSignal > 2 && signal3Value)
		{
			source = signal3Source
		}
		else if (nbSignal > 3 && signal4Value)
		{
			source = signal4Source
		}
		else
		{
			source = signal1SourceAt0
		}
	}

	function updateToggle(toggle)
	{
		if ((signal1Value === 2 && noBlink === false) ||
			(nbSignal > 1 && signal2Value === 2 && !signal1Value) ||
			(nbSignal > 2 && signal3Value === 2 && !signal1Value && !signal2Value) ||
			(nbSignal > 3 && signal4Value === 2 && !signal1Value && !signal2Value && !signal3Value) ||
			signal1canError ||
			(nbSignal > 1 && signal2canError) ||
			(nbSignal > 2 && signal3canError)  ||
			(nbSignal > 3 && signal4canError))
		{
			if ((toggle && opacity) || (!toggle && !opacity ) ) //sync toggle with other pictos
				opacity = !opacity
		}
		else
		{
			opacity = 1.0
		}
	}
}
