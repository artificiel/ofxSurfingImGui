#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// add to custom tags to log system
	ui.AddLogTag(myTag1, ofColor::yellow);
	ui.AddLogTag(myTag2, ofColor::orange);

	// callback to log
	listener = speed.newListener([this](float& v) {
		ofLogNotice() << v;

		string s = speed.getName() + ": " + ofToString(speed.get(), 1);
		ui.AddToLog(s, myTag1);
		});

}

//--------------------------------------------------------------
void ofApp::update()
{
	if (ofGetFrameNum() % 60 == 0) {
		static int count = 0;
		string s = "COUNT " + ofToString(++count);
		ui.AddToLog(s, "NOTICE");
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	drawGui();

	drawScene();
}

//--------------------------------------------------------------
void ofApp::drawGui()
{
	if (!bGui) return;
	// Not mandatory, but
	// this will allow to hide the Log Window too. 
	// That's bc is auto drawn when calling ui.End()!

	ui.Begin();
	{
		// This is a raw ImGui window
		static bool windowOpen = true;
		if (windowOpen) {
			ImGuiWindowFlags flags = ImGuiWindowFlags_None;
			flags += ImGuiWindowFlags_AlwaysAutoResize;
			if (ImGui::Begin("Test Quaternions", &windowOpen, flags))
			{
				ui.AddLabelBig("Quaternion");
				ui.AddLabel("ofParameter<glm::quat> curRot{\"QuatRot\", \nglm::quat(0, 1, 0, 0), \nglm::quat(-1, -1, -1, -1), \nglm::quat(1, 1, 1, 1)};");
				ui.AddSpacingBig();
				ui.Add(curRot);
			}
			ImGui::End();
		}

		//--

		// Close the Window by pressing the top right X.
		// This state is handled internally by bGui bool param!
		// Press space to toggle bGui and show it again.

		static bool bConstraint = 0;
		if (bGui && bConstraint) {
			IMGUI_SUGAR__WINDOWS_CONSTRAINTS;
		}
		if (ui.BeginWindow(bGui))
		{
			string s = "HELP\n\n";
			s += "Enable the Log Window using the above rounded toggle.\n\n";
			s += "Drag the mouse and click left or right button outside or inside the UI, ";
			s += "move speed slider... \n\nThen go look into the Log Window!";
			s += "\n\nPress SPACE to show/hide the UI.";

			ui.AddLogToggle(); // populate a toggle for the internal show log param.
			ui.AddMinimizerToggle(); // populate a toggle for the internal minimized param.

			//if (!ui.isMinimized()) 
			if (ui.isMaximized()) // does the same than the above line
			{
				ui.AddKeysToggle(); // populate a toggle for the internal keys enabler param.
				string s2 = "Keys Enabler \n\nwill allow some \ninternal key commands.\n\n";
				s2 += "Press ` to toggle the Minimizer state.\n";
				s2 += "Press L to toggle the Log Window visible.";
				ui.AddTooltip(s2); // a tooltip will be pinned to the previous widget!

				ui.AddAutoResizeToggle();
				ui.AddToggle("Constraints", bConstraint, OFX_IM_CHECKBOX);
			}

			ui.AddSpacingBigSeparated();

			ui.Add(bEnable, OFX_IM_TOGGLE_BIG_BORDER_BLINK); // blinks when true
			s = "Will enable:\n\n";
			s += "1. Bigger font\n";
			s += "   (on above HELP text)\n";
			s += "2. Blink text\n";
			s += "3. Show/hide bottom widgets\n";
			s += "4. When Enabled is false, \nSpeed will be deactivated";
			ui.AddTooltip(s);

			ui.AddSpacingBigSeparated();

			// two different presentations depending if minimized or not
			if (ui.isMinimized()) // minimized
			{
				ui.Add(speed, OFX_IM_HSLIDER_SMALL_NO_LABELS); // smaller with no name and no value number
				ui.AddTooltip(speed, true, false); // tool-tip with name and value
				ui.AddSpacingDouble();

				// make font bigger
				if (bEnable) ui.PushFontStyle(OFX_IM_FONT_BIG);
				ui.AddTooltipHelp(s);
				if (bEnable) ui.PopFontStyle();
			}
			else // not minimized aka maximized
			{
				// make it uppercase and add an extra space (true, true)
				if (bEnable) ui.AddLabelHuge("00_HelloWorld2", true, true);
				else ui.AddLabelBig("00_HelloWorld2", true, true);

				ui.AddSpacingDouble();

				// make it blink
				if (bEnable) ui.BeginBlinkText();
				// make font bigger
				if (bEnable) ui.PushFontStyle(OFX_IM_FONT_BIG);

				ui.AddLabel(s);

				if (bEnable) ui.PopFontStyle();
				if (bEnable) ui.EndBlinkText();

				ui.AddSpacingBigSeparated();

				if (!bEnable) {
					ui.PushInactive();
					ui.Add(speed, OFX_IM_HSLIDER);
					ui.PopInactive();
					s = "Widget is deactivated\nwhen Enabled is false\nSo can not be touched.";
					ui.AddLabel(s);

				}
				else {
					ui.Add(speed, OFX_IM_HSLIDER);
					s = "Widget is activated\nwhen Enabled\nSo it can be touched.";
					ui.AddTooltip(s);
				}

				if (bEnable)
				{
					ui.AddSpacing();
					ui.AddSpacingSeparated();
					ui.AddSpacingDouble();

					// A right aligned extra minimizer
					// but using a local bool param.
					// not that is not stored into settings file,
					// but other internal toggles it does!
					static ofParameter<bool> bMin{ "", true };
					ui.AddMinimizerXsToggle(bMin);
					if (!bMin)
					{
						ui.AddGroup(params, SurfingGuiGroupStyle_Collapsed); // collapsed on startup
					}
				}

				//--

				ui.AddSpacingBigSeparated();
				ui.DrawWidgetsResetUI();//populate ResetUI button directly.
				//ui.resetUISettings();//exposed method.
			}

			ui.EndWindow();
		}
	}
	ui.End();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	ui.AddToLog("KEY: " + ofToString(char(key)), "WARNING");

	if (key == ' ') bGui = !bGui;
	if (key == 'f') ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (ui.isMouseOverGui()) return; // don't log if we are touching the ui

	lastMouse = glm::vec2(x, y);

	string sb = "";
	if (button == 0) sb = "LEFT";
	else if (button == 2) sb = "RIGHT";
	string s = "Mouse Click " + ofToString(x) + "," + ofToString(y) + " " + sb;

	ui.AddToLog(s, myTag2);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (ui.isMouseOverGui()) return; // don't log if we are touching the ui

	glm::vec2 mouse(x, y);
	glm::quat yRot = glm::angleAxis(ofDegToRad(x - lastMouse.x) * dampen, glm::vec3(0, 1, 0));
	glm::quat xRot = glm::angleAxis(ofDegToRad(y - lastMouse.y) * dampen, glm::vec3(-1, 0, 0));
	curRot.set(xRot * yRot * curRot.get());
	lastMouse = mouse;

	string s = "Mouse Drag  " + ofToString(x) + "," + ofToString(y);

	ui.AddToLog(s, "VERBOSE");
}

//--------------------------------------------------------------
void ofApp::drawScene() {
	ofPushStyle();
	ofSetColor(ofColor::white, 16);
	ofNoFill();
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 40);
	auto axis = glm::axis(curRot.get());
	ofRotateDeg(ofRadToDeg(glm::angle(curRot.get())), axis.x, axis.y, axis.z);
	ofDrawSphere(0, 0, 0, 200);
	ofPopMatrix();
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::exit()
{
}