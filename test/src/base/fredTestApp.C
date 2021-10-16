//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fredTestApp.h"
#include "fredApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
fredTestApp::validParams()
{
  InputParameters params = fredApp::validParams();
  return params;
}

fredTestApp::fredTestApp(InputParameters parameters) : MooseApp(parameters)
{
  fredTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fredTestApp::~fredTestApp() {}

void
fredTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fredApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fredTestApp"});
    Registry::registerActionsTo(af, {"fredTestApp"});
  }
}

void
fredTestApp::registerApps()
{
  registerApp(fredApp);
  registerApp(fredTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fredTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fredTestApp::registerAll(f, af, s);
}
extern "C" void
fredTestApp__registerApps()
{
  fredTestApp::registerApps();
}
