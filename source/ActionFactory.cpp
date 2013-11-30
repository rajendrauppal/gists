/*
The MIT License (MIT)

Copyright (c) 2013 rajendrauppal

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

class Action
{
public:
	virtual void Execute() = 0;
};

class DMGMountAction : public Action
{
public:
	virtual void Execute() {}
};

class ExtractZIPAction : public Action
{
public:
	virtual void Execute() {}
};

class ActionFactory
{
public:
	enum ActionType { DMG, ZIP };

	static Action * GetActionObject(ActionType at)
	{
		Action * action = (Action*)0;

		if ( DMG == at ) {
			action = new DMGMountAction();
		} else if ( ZIP == at ) {
			action = new ExtractZIPAction();
		}

		return action;
	}

	static void ReleaseActionObject(Action * action)
	{
		delete action;
		action = (Action*)0;
	}
};

int main()
{
	Action * action = ActionFactory::GetActionObject(ActionFactory::DMG);
	action->Execute();
	ActionFactory::ReleaseActionObject(action);

	action = ActionFactory::GetActionObject(ActionFactory::ZIP);
	action->Execute();
	ActionFactory::ReleaseActionObject(action);

	return 0;
}