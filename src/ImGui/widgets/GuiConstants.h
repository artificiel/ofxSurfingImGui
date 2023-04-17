
#pragma once


/*

	This class has useful constants:
	widgets sizes, default themes, fonts, ...etc.
	To be used around many classes.

*/


//----

// To fix weird behaviors 
// when too big or too small resized windows

#define WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL 300 
//#define WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL 250 
// when a window width is less than that, 
// we can consider that the window is too small.
// we will use another layout pattern for some widgets.

#define PADDING_COMBO 0 // to fix some weird label forcing oversize window

//----

// Will be applied as minimum 
// and standard window shape
#define PANEL_WIDGETS_WIDTH 250
#define PANEL_WIDGETS_HEIGHT 100
#define PANEL_WIDGETS_WIDTH_MIN 200
#define PANEL_WIDGETS_HEIGHT_MIN 100

// LEGACY
#define PANEL_WIDTH_MIN PANEL_WIDGETS_WIDTH_MIN 
#define PANEL_HEIGHT_MIN PANEL_WIDGETS_HEIGHT_MIN

//----

// Default Themes files

// Files must be in the default place:
// ofxSurfingImGui\Examples\09_ThemeEditor\bin\data\Gui\themes\
// Note that "/Gui/" is the default global path, but could be changed. (setName() or setPath())
// When files are not located there, then will load a hardcoded default theme: 
// ofxImGuiSurfing::ImGui_ThemeMoebiusSurfingV2();

// Night
#define THEME_NAME_NIGHT "moebiusSurfingV2.ini"

// Day
#define THEME_NAME_DAY "AiekickRedDark.ini"

//----

// Default Font

// Notice that if not any font file is located, will work as ImGui default,
// So you don't need to put any files on bin/data to compile right!

// LEGACY Font
#define FONT_DEFAULT_FILE_LEGACY "telegrama_render.otf"
#define FONT_DEFAULT_SIZE_LEGACY 11

// New font LEGACY
#define FONT_DEFAULT_SIZE 14
#define FONT_DEFAULT_FILE "JetBrainsMono-Bold.ttf"

#define OFX_IM_FONT_DEFAULT_FILE FONT_DEFAULT_FILE 
//#define OFX_IM_FONT_DEFAULT_FILE "JetBrainsMono-Bold.ttf"

//--

// Other Candidates

//#define FONT_DEFAULT_SIZE 14
//#define FONT_DEFAULT_FILE "JetBrainsMono-Medium.ttf"

//#define FONT_DEFAULT_SIZE 13
//#define FONT_DEFAULT_FILE "PrgmtB.ttf"

//#define FONT_DEFAULT_SIZE 13
//#define FONT_DEFAULT_FILE "PrgmtR.ttf"

//#define FONT_DEFAULT_SIZE 14
//#define FONT_DEFAULT_FILE "Ruda-Bold.ttf"

//----

// Ratio Sizes between sizes of a widget type. 

//TODO:
// fix for HSLIDERS.. 
// should be used by toggles and buttons too!
#define OFX_IM_WIDGETS_RATIO_DEFAULT 0.7f
#define OFX_IM_WIDGETS_RATIO_BIG 1.5f
#define OFX_IM_WIDGETS_RATIO_MINI 0.16f
#define OFX_IM_WIDGETS_RATIO_SMALL 0.4f

// Window scrolling size on some windows/groups
#define HEIGHT_SCROLL_GROUP 400

// Knobs format to 3 decimals
#define OFX_IM_FORMAT_WIDGETS "%.1f"
#define OFX_IM_FORMAT_KNOBS "%.2f"
#define OFX_IM_FORMAT_SLIDERS "%.2f"
//TODO:
#define OFX_IM_FORMAT_WIDGETS_INT "%d"
#define OFX_IM_FORMAT_KNOBS_INT "%d"
#define OFX_IM_FORMAT_SLIDERS_INT "%d"

//----

#define OFX_IMGUI_CONSTRAIT_WINDOW_SHAPE 
// Constraint some window minimal shape sizes.

#define DEFAULT_AMOUNT_PRESETS 4 // Layout Presets Engine

//TODO:
// Testing central view-port
//#define FIXING_DOCKING		// Need to fix yet
#define FIXING_DRAW_VIEWPORT	// To debug free space

// DEPRECATED
// Font sizes
#define IM_FONT_DEFAULT 0
#define IM_FONT_BIG 1
#define IM_FONT_HUGE 2
#define IM_FONT_HUGE_XXL 3

//----

#define TEXT_INACTIVE_ALPHA 0.30f // for using on toggle buttons

#define BLINK_MIN 0.2f 
#define BLINK_MAX 0.8f 

#define FACTOR_DARKEN 0.2f 

#define VERTICAL_AMOUNT_UNITS 5.0f 

//----

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

//------

namespace ofxImGuiSurfing
{
	//--

	//--------------------------------------------------------------
	enum SurfingFontTypes
	{
		OFX_IM_FONT_DEFAULT = 0,
		OFX_IM_FONT_BIG,
		OFX_IM_FONT_HUGE,
		OFX_IM_FONT_HUGE_XXL,

		OFX_IM_FONT_AMOUNT
	};

	//--

	// NOTE:
	// Now, these sizes are usually related to height! 
	// Because widgets widths are handled by the API args!
	// TODO: IDEA: remake width management notation to use of percents.

	//--------------------------------------------------------------
	enum SurfingGuiTypes
	{
		OFX_IM_DEFAULT = 0, // Default style for each widget. (kind of like ofxImGui does)
		OFX_IM_HIDDEN, // Omit widget. don't let spacing there.
		OFX_IM_DISABLED, // Make it invisible, preserve the void spacing. it's a common height but could differs..
		OFX_IM_INACTIVE, // Draws the widget. but makes it inactive. disables mouse control.
		OFX_IM_SPACING, // Make it invisible, preserve a custom (one standard line) spacing.

		//TODO: could be added an extra argument 
		// to allow different appearance for inactive types..

		//--

		// Types / Styles

		//--

		// Bool and void 

		// Button

		//OFX_IM_BUTTON_MINI, // 1 = default. too small to place text well.
		OFX_IM_BUTTON_SMALL, // 1 = default
		OFX_IM_BUTTON, // 1.25
		OFX_IM_BUTTON_MEDIUM, // 1.5
		OFX_IM_BUTTON_BIG, // 2
		OFX_IM_BUTTON_BIG_XXL, // 3
		OFX_IM_BUTTON_BIG_XXXL, // 4

		// Border

		OFX_IM_BUTTON_SMALL_BORDER,
		OFX_IM_BUTTON_BORDER,
		OFX_IM_BUTTON_MEDIUM_BORDER,
		OFX_IM_BUTTON_BIG_BORDER,
		OFX_IM_BUTTON_BIG_XXL_BORDER,
		OFX_IM_BUTTON_BIG_XXXL_BORDER,

		// Border Blink 

		OFX_IM_BUTTON_SMALL_BORDER_BLINK,
		OFX_IM_BUTTON_BORDER_BLINK,
		OFX_IM_BUTTON_MEDIUM_BORDER_BLINK,
		OFX_IM_BUTTON_BIG_BORDER_BLINK,
		OFX_IM_BUTTON_BIG_XXL_BORDER_BLINK,
		OFX_IM_BUTTON_BIG_XXXL_BORDER_BLINK,

		//--

		// Bool (not void)

		// Toggle

		OFX_IM_CHECKBOX, // ofxImGui standard
		OFX_IM_TOGGLE,
		//OFX_IM_TOGGLE_MINI,
		OFX_IM_TOGGLE_SMALL,
		OFX_IM_TOGGLE_MEDIUM,
		OFX_IM_TOGGLE_BIG,
		OFX_IM_TOGGLE_BIG_XXL,
		OFX_IM_TOGGLE_BIG_XXXL,

		// Border

		OFX_IM_TOGGLE_SMALL_BORDER,
		OFX_IM_TOGGLE_BORDER,
		OFX_IM_TOGGLE_MEDIUM_BORDER,
		OFX_IM_TOGGLE_BIG_BORDER,
		OFX_IM_TOGGLE_BIG_XXL_BORDER,
		OFX_IM_TOGGLE_BIG_XXXL_BORDER,

		// Border Blink 

		OFX_IM_TOGGLE_SMALL_BORDER_BLINK,
		OFX_IM_TOGGLE_BORDER_BLINK,
		OFX_IM_TOGGLE_MEDIUM_BORDER_BLINK,
		OFX_IM_TOGGLE_BIG_BORDER_BLINK,
		OFX_IM_TOGGLE_BIG_XXL_BORDER_BLINK,
		OFX_IM_TOGGLE_BIG_XXXL_BORDER_BLINK,

		//--

		// Rounded

		OFX_IM_TOGGLE_ROUNDED,
		OFX_IM_TOGGLE_ROUNDED_MINI_XS,//TODO:
		OFX_IM_TOGGLE_ROUNDED_MINI,
		OFX_IM_TOGGLE_ROUNDED_SMALL,
		OFX_IM_TOGGLE_ROUNDED_MEDIUM,
		OFX_IM_TOGGLE_ROUNDED_BIG,

		// LEGACY. Now we removed 'button' word
		OFX_IM_TOGGLE_BUTTON_ROUNDED, // same size than small.
		OFX_IM_TOGGLE_BUTTON_ROUNDED_MINI_XS,//TODO:
		OFX_IM_TOGGLE_BUTTON_ROUNDED_MINI,
		OFX_IM_TOGGLE_BUTTON_ROUNDED_SMALL,
		OFX_IM_TOGGLE_BUTTON_ROUNDED_MEDIUM,
		OFX_IM_TOGGLE_BUTTON_ROUNDED_BIG,

		//--

		// FLOAT / INT Styles

		OFX_IM_SLIDER, // ofxImGui standard

		// Big Sliders

		// Horizontal

		OFX_IM_HSLIDER_BIG,
		OFX_IM_HSLIDER_BIG_NO_NAME,
		OFX_IM_HSLIDER_BIG_NO_NUMBER,
		OFX_IM_HSLIDER_BIG_NO_LABELS,
		OFX_IM_HSLIDER_SMALL,
		OFX_IM_HSLIDER_SMALL_NO_NAME,
		OFX_IM_HSLIDER_SMALL_NO_NUMBER,
		OFX_IM_HSLIDER_SMALL_NO_LABELS,
		OFX_IM_HSLIDER,
		OFX_IM_HSLIDER_NO_NAME,
		OFX_IM_HSLIDER_NO_NUMBER,
		OFX_IM_HSLIDER_NO_LABELS,
		OFX_IM_HSLIDER_MINI,
		OFX_IM_HSLIDER_MINI_NO_NAME,
		OFX_IM_HSLIDER_MINI_NO_LABELS,
		OFX_IM_HSLIDER_MINI_NO_NUMBER,

		// Vertical

		OFX_IM_VSLIDER,
		OFX_IM_VSLIDER_NO_NAME,
		OFX_IM_VSLIDER_NO_NUMBER,
		OFX_IM_VSLIDER_NO_LABELS,

		OFX_IM_PROGRESS_BAR_MINI,
		OFX_IM_PROGRESS_BAR_MINI_NO_TEXT,
		OFX_IM_PROGRESS_BAR,
		OFX_IM_PROGRESS_BAR_NO_TEXT,
		OFX_IM_STEPPER,
		OFX_IM_STEPPER_NO_LABEL,
		OFX_IM_DRAG,

		//--

		// Knobs

		// Notice that full width by default, is usually too big!
		// LEGACY
		OFX_IM_KNOB, // LEGACY
		OFX_IM_KNOB_TRAIL, // LEGACY. decorated

		//TODO:
		// Add more arguments: no label, no number...
		// Adding NEW style knobs, 
		// taken from Simon Altschuler 
		// https://github.com/altschuler/imgui-knobs

		OFX_IM_KNOB_TICKKNOB,
		OFX_IM_KNOB_DOTKNOB,
		OFX_IM_KNOB_WIPERKNOB,
		OFX_IM_KNOB_WIPERONLYKNOB,
		OFX_IM_KNOB_WIPERDOTKNOB,
		OFX_IM_KNOB_STEPPEDKNOB,
		OFX_IM_KNOB_SPACEKNOB,

		//--

		OFX_IM_COMBO_MULTI,

		//TODO: 
		// multiple controls for fine tweak:
		//slider + drag + stepper
		/*
		// A bundle of controls
		// for a single param
		ui.AddLabelBig(lineWidth.getName());
		ImGui::PushButtonRepeat(true); // -> pushing to repeat trigs
		{
			if (ui.Add(bPrevious, OFX_IM_BUTTON_BIG, 2))
			{
				lineWidth -= 0.1f;
				lineWidth = ofClamp(lineWidth, lineWidth.getMin(), lineWidth.getMax());
			}
			ImGui::SameLine();
			if (ui.Add(bNext, OFX_IM_BUTTON_BIG, 2))
			{
				lineWidth += 0.1f;
				lineWidth = ofClamp(lineWidth, lineWidth.getMin(), lineWidth.getMax());
			}
		}
		ImGui::PopButtonRepeat();
		*/

		//--

		// Strings

		OFX_IM_TEXT_INPUT,//TODO:
		OFX_IM_TEXT_INPUT_NO_NAME,//TODO:
		OFX_IM_TEXT_INPUT_NAMED,//TODO:

		OFX_IM_TEXT_DISPLAY,
		OFX_IM_TEXT_BIG,//TODO:
		OFX_IM_TEXT_LONG,//TODO: paragraph size
		//TODO: add labels
		//OFX_IM_LABEL,//big font not accessible here..
		//OFX_IM_LABEL_BIG,

		//--

		// Colors

		OFX_IM_COLOR, // default
		OFX_IM_COLOR_INPUTS, // default
		OFX_IM_COLOR_INPUTS_NO_ALPHA, // without the alpha control
		OFX_IM_COLOR_NO_INPUTS, // without inputs
		OFX_IM_COLOR_NO_INPUTS_NO_ALPHA, // without inputs
		OFX_IM_COLOR_NO_NAME, //TODO: without name or controls
		OFX_IM_COLOR_BOX, // small box color without controls
		OFX_IM_COLOR_BOX_FULL_WIDTH, // full width
		OFX_IM_COLOR_BOX_FULL_WIDTH_BIG, // double height
		OFX_IM_COLOR_BOX_FULL_WIDTH_NO_ALPHA, // full width. no alpha
		OFX_IM_COLOR_BOX_FULL_WIDTH_BIG_NO_ALPHA, // double height. no alpha

		//--

		// Multi dim 

		//TODO: 
		// for glm::vec2 vec3 vec4
		OFX_IM_MULTIDIM_SPLIT_SLIDERS,
		OFX_IM_MULTIDIM_SPLIT_SLIDERS_FOLDERED,
		//OFX_IM_MULTIDIM_SPLIT_STEPPERS,//TODO:
		//OFX_IM_MULTIDIM_SPLIT_DRAGS,

		//--

		OFX_IM_NUM_TYPES
	};

	//--

	// Group Style / State

	//TODO: 
	// NEW API V2
	// To simplify the API
	// We can use one only flag argument and multiple possibilities at the same time are allowed.
	typedef int SurfingGuiGroupStyle;
	enum SurfingGuiGroupStyle_
	{
		SurfingGuiGroupStyle_None = 1 << 0,
		SurfingGuiGroupStyle_Collapsed = 1 << 1,
		SurfingGuiGroupStyle_NoHeader = 1 << 2,
		SurfingGuiGroupStyle_Hidden = 1 << 3,
		SurfingGuiGroupStyle_HeaderSmall = 1 << 4 // uses ImGui tree without big header. just arrow.
		//SurfingGuiGroupStyle_NoArrow = 1 << 5,
	};

	//--

	// Group Style
	//TODO: kind of deprecated? replace by SurfingGuiGroupStyle_Collapsed?
	//it's used internally in some methods.. make it private?
	///*
	//--------------------------------------------------------------
	enum SurfingGuiTypesGroups
	{
		OFX_IM_GROUP_DEFAULT = 0,// TODO: BUG: it's forced collapsed
		OFX_IM_GROUP_COLLAPSED,
		OFX_IM_GROUP_TREE_EX, // TODO: can be collapsed or opened
		OFX_IM_GROUP_TREE, // TODO: BUG: it's forced collapsed
		OFX_IM_GROUP_SCROLLABLE,
		OFX_IM_GROUP_HIDDEN_HEADER, // hide header. TODO; fails on first group. not working
		OFX_IM_GROUP_HIDDEN, // hide header and all the content

		//OFX_IM_GROUP_WINDOWED, // creates a windows to populate into. Notice that must be a root group. can't be a nested! 
		//guiMnager is not in scope here!

		OFX_IM_GROUP_NUM_TYPES
	};
	//*/

	//----

	//TODO: 
	// FEATURE:

	// Flags

	// Add a new flag to handle labels, 
	// active or tool tip NEW features
	typedef int SurfingGuiFlags;
	enum SurfingGuiFlags_
	{
		SurfingGuiFlags_None = 1 << 0,
		SurfingGuiFlags_NoTitle = 1 << 1,
		SurfingGuiFlags_NoInput = 1 << 2,
		SurfingGuiFlags_TooltipValue = 1 << 3,
		SurfingGuiFlags_TooltipHelp = 1 << 4,
		SurfingGuiFlags_DragHorizontal = 1 << 5,
		SurfingGuiFlags_Hidden = 1 << 6,
		SurfingGuiFlags_Disabled = 1 << 7,
		SurfingGuiFlags_Inactived = 1 << 8,
	};

	//----

	// Helper to get the styles name for debugging purposes
	//--------------------------------------------------------------
	inline static std::string getSurfingGuiTypesGroupsName(int i)
	{
		std::string _groupInfo;
		if (i == 0) _groupInfo = "OFX_IM_GROUP_DEFAULT";
		else if (i == 1) _groupInfo = "OFX_IM_GROUP_COLLAPSED";
		else if (i == 2) _groupInfo = "OFX_IM_GROUP_TREE_EX";
		else if (i == 3) _groupInfo = "OFX_IM_GROUP_TREE";
		else if (i == 4) _groupInfo = "OFX_IM_GROUP_SCROLLABLE";
		else if (i == 5) _groupInfo = "OFX_IM_GROUP_HIDDEN_HEADER";
		else if (i == 6) _groupInfo = "OFX_IM_GROUP_HIDDEN";
		//else if (i == 7) _groupInfo = "OFX_IM_GROUP_WINDOWED";
		else _groupInfo = "OFX_IM_GROUP UNKNOWN";

		return _groupInfo;
	}


	//---------------


	//----

	// SUGAR SNIPPETS

	//--

	// 1.

	// BUG:
	// Annoying behavior: 
	// sometimes the sliders are bigger bc the text long or something,
	// Then all the window panels is being resized bigger 
	// if auto resize is enabled!

	// workaround

	//TODO: 
	// A nice idea could be to get the longer param label name width 
	// and use this max width to apply to our layouting engine...

	// Some macro sugar to help fix how sliders force auto resize the panel widths.
	// It's a 'rare behavior' that I am trying to correct doing this.

	//--

	//#define DEFAULT_LAYOUT_SLIDERS_BEHAVIOR 
	// Comment this line to use a workaround 
	// to weird ImGui auto resize layouting on sliders widgets...

	//--

#ifndef DEFAULT_LAYOUT_SLIDERS_BEHAVIOR

	// A. Relative to panel width
	// less than threshold will make half window width

#define IMGUI_SUGAR__WIDGETS_PUSH_WIDTH \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x / 2.f); }

#define IMGUI_SUGAR__WIDGETS_POP_WIDTH \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PopItemWidth(); }

#endif

	//--

	//// B. Using an absolute size

	//#define IMGUI_LABELS_WIDTH_DEFAULT 95
	//#define IMGUI_SUGAR__WIDGETS_PUSH_WIDTH ImGui::PushItemWidth(-IMGUI_LABELS_WIDTH_DEFAULT);
	//#define IMGUI_SUGAR__WIDGETS_POP_WIDTH ImGui::PopItemWidth();

	//--

#ifdef DEFAULT_LAYOUT_SLIDERS_BEHAVIOR

	// C. To bypass and do nothing.

#define IMGUI_SUGAR__WIDGETS_PUSH_WIDTH ;
#define IMGUI_SUGAR__WIDGETS_POP_WIDTH ;

#endif

	//--

	// 2.

	// For OFX_IM_STEPPER

#define STEP_FACTOR_WINDOW_IS_SMALL_FOR_INT .72f
//#define STEP_FACTOR_WINDOW_IS_SMALL_FOR_INT .67f

//#define STEP_FACTOR_WINDOW_IS_SMALL_FOR_FLOAT .7f 
#define STEP_FACTOR_WINDOW_IS_SMALL_FOR_FLOAT .72f 
// To allow see 3 decimals seen well, 
// but requires preferably shorter label name.

#define IMGUI_SUGAR__STEPPER_WIDTH_PUSH_FLOAT \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x * STEP_FACTOR_WINDOW_IS_SMALL_FOR_FLOAT); }

#define IMGUI_SUGAR__STEPPER_WIDTH_POP_FLOAT \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PopItemWidth(); }

#define IMGUI_SUGAR__STEPPER_WIDTH_PUSH \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x * STEP_FACTOR_WINDOW_IS_SMALL_FOR_INT); }

#define IMGUI_SUGAR__STEPPER_WIDTH_POP \
	if (ImGui::GetContentRegionAvail().x < WINDOW_WIDTH_THRESHOLD_TO_CONSIDER_SMALL) { ImGui::PopItemWidth(); }

	//--

#define TEXT_LABEL_TO_RESIZE "0123456789"

	//TODO:
	// This is a 10 chars string that we will use as default label width, to name widgets.
	// another approach depending on text label. or to use TEXT_LABEL_TO_RESIZE with a fixed chars long.
	// that could be weird because each slider will have a different width.
	//const ImVec2 sz = ImGui::CalcTextSize(TEXT_LABEL_TO_RESIZE); \
	 
	//TODO:
	// Fix auto resize loop grow...
	// Using an standard text size for the widgets 
	//#define IMGUI_SUGAR__STEPPER_WIDTH_PUSH \
	//	const auto sztx = ImGui::CalcTextSize(TEXT_LABEL_TO_RESIZE); \
	//	const float gap = 40; \
	//	ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - sztx.x - gap);
	//#define IMGUI_SUGAR__STEPPER_WIDTH_POP ImGui::PopItemWidth();

	//----

	// 3.

	// Adds mouse wheel control to the last/previous ofParam widget (float/int) rendered.

//#define IMGUI_SUGAR__SLIDER_ADD_MOUSE_WHEEL(arg1, arg2, arg3) ofxImGuiSurfing::AddMouseWheel(arg1, arg2, arg3);
#define IMGUI_SUGAR__SLIDER_ADD_MOUSE_WHEEL(arg1, arg2) ofxImGuiSurfing::AddMouseWheel(arg1, arg2); // param, flip

//--

//// macOS fix
//#define IMGUI_SUGAR__SLIDER_ADD_MOUSE_WHEEL(arg1) ofxImGuiSurfing::AddMouseWheel(arg1, false); // param, flip

//--

// Amount of steps per widgets. will calculate range between max/min.
#define MOUSE_WHEEL_STEPS 100.f

// How more fine is when CTRL pressed 
#define MOUSE_WHEEL_FINETUNE_CTRL_RATIO 0.20f
//#define MOUSE_WHEEL_FINETUNE_CTRL_RATIO 5

//----

// 3.

// Adds Constraints Window Shapes (width and height)

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS_FULL \
{ \
ImVec2 size_min = ImVec2(500, 500); \
ImVec2 size_max = ImVec2(ofGetWidth() * 0.9f, ofGetHeight() * 0.9f); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS_BIG \
{ \
ImVec2 size_min = ImVec2(400, 400); \
ImVec2 size_max = ImVec2(600, 600); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS_MEDIUM \
{ \
ImVec2 size_min = ImVec2(300, 300); \
ImVec2 size_max = ImVec2(500, 500); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS \
{ \
ImVec2 size_min = ImVec2(220, 220); \
ImVec2 size_max = ImVec2(400, 400); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS_SMALL \
{ \
ImVec2 size_min = ImVec2(150, 150); \
ImVec2 size_max = ImVec2(250, 250); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTS_MINI \
{ \
ImVec2 size_min = ImVec2(100, 100); \
ImVec2 size_max = ImVec2(100, 100); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

//--

// Constraint for width only

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW_FULL \
{ \
ImVec2 size_min = ImVec2(500, -1); \
ImVec2 size_max = ImVec2(ofGetWidth() * 0.9f, ofGetHeight() * 0.9f); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW_BIG \
{ \
ImVec2 size_min = ImVec2(400, -1); \
ImVec2 size_max = ImVec2(600, -1); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW_MEDIUM \
{ \
ImVec2 size_min = ImVec2(300, -1); \
ImVec2 size_max = ImVec2(500, -1); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW \
{ \
ImVec2 size_min = ImVec2(220, -1); \
ImVec2 size_max = ImVec2(400, -1); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW_SMALL \
{ \
ImVec2 size_min = ImVec2(150, -1); \
ImVec2 size_max = ImVec2(250, -1); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

#define IMGUI_SUGAR__WINDOWS_CONSTRAINTSW_MINI \
{ \
ImVec2 size_min = ImVec2(100, -1); \
ImVec2 size_max = ImVec2(100, -1); \
ImGui::SetNextWindowSizeConstraints(size_min, size_max); \
} \

};
