//
// Copyright � 2012 Linaro Limited
//
// This file is part of the glmark2 OpenGL (ES) 2.0 benchmark.
//
// glmark2 is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// glmark2 is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// glmark2.  If not, see <http://www.gnu.org/licenses/>.
//
// Authors:
//  Jesse Barker
//
#include "scene.h"
#include "util.h"

class ShadowPrivate
{
};

SceneShadow::SceneShadow(Canvas& canvas) :
    Scene(canvas, "shadow"),
    priv_(0)
{
}

SceneShadow::~SceneShadow()
{
    delete priv_;
}

bool
SceneShadow::supported(bool show_errors)
{
    return show_errors;
}

bool
SceneShadow::load()
{
    running_ = false;
    return true;
}

void
SceneShadow::unload()
{
}

bool
SceneShadow::setup()
{
    if (!Scene::setup())
        return false;

    priv_ = new ShadowPrivate();
    // Set core scene timing after actual initialization so we don't measure
    // set up time.
    startTime_ = Util::get_timestamp_us() / 1000000.0;
    lastUpdateTime_ = startTime_;
    running_ = true;

    return true;
}

void
SceneShadow::teardown()
{
    // Add scene-specific teardown here
    Scene::teardown();
}

void
SceneShadow::update()
{
    Scene::update();
    // Add scene-specific update here
}

void
SceneShadow::draw()
{
}

Scene::ValidationResult
SceneShadow::validate()
{
    return Scene::ValidationUnknown;
}
