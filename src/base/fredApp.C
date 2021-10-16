#include "fredApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fredApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

fredApp::fredApp(InputParameters parameters) : MooseApp(parameters)
{
  fredApp::registerAll(_factory, _action_factory, _syntax);
}

fredApp::~fredApp() {}

void
fredApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"fredApp"});
  Registry::registerActionsTo(af, {"fredApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fredApp::registerApps()
{
  registerApp(fredApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fredApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fredApp::registerAll(f, af, s);
}
extern "C" void
fredApp__registerApps()
{
  fredApp::registerApps();
}
