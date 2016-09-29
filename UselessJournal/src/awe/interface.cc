#include "interface.h"

using namespace Awesomium;

UJApp::UJApp() : app_(Application::Create()), view_(0) {
	app_->set_listener(this);
}
UJApp::~UJApp() {
	if (view_)
		app_->DestroyView(view_);
	if (app_)
		delete app_;
}
void UJApp::Run() {
	app_->Run();
}

//

void UJApp::OnLoaded() {
	view_ = View::Create(800, 460);
	// < Set up your View here. >
}
void UJApp::OnUpdate() {

}
void UJApp::OnShutdown() {

}

// -------- //
// BINDINGS //
// -------- //
void UJApp::BindMethods(WebView* web_view) {
	JSValue result = web_view->CreateGlobalJavascriptObject(WSLit("app"));

	if (result.IsObject()) {
		JSObject& ao = result.ToObject();

		md_.Bind(ao, WSLit("sayHi"), JSDelegate(this, &UJApp::js_SayHi));
	}

	web_view->set_js_method_handler(&md_);
}
// Methods
void UJApp::js_SayHi(WebView* caller, const JSArray& args) {
	app_->ShowMessage("Hello there");
}

//---------------------//
// Interface functions //
//---------------------//

int UJUI::Interface() {
	UJApp app;
	app.Run();

	return 0;
}