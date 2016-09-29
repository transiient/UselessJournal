#pragma once

#include "application.h"
#include "view.h"
#include "method_dispatcher.h"
#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace Awesomium;

class UJApp : public Application::Listener {
	Application* app_;
	View* view_;
	MethodDispatcher md_;
public:
	UJApp();

	virtual ~UJApp();

	void Run();

	// Inherited from Application::Listener
	virtual void OnLoaded();

	// Inherited from Application::Listener
	virtual void OnUpdate();

	// Inherited from Application::Listener
	virtual void OnShutdown();
	
	// -------- //
	// BINDINGS //
	// -------- //
	void BindMethods(WebView* web_view);
	// Methods
	void js_SayHi(WebView* caller, const JSArray& args);
};
class UJUI {
public:
	static int Interface();
};