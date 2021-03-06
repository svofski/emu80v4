/*
 *  Emu80 v. 4.x
 *  © Viktor Pykhonin <pyk@mail.ru>, 2016-2017
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PALWX_H
#define PALWX_H

#include <string>
#include <vector>

#include "../EmuTypes.h"


bool palWxInit(int argc, char** argv);
void palWxQuit();

std::string palOpenFileDialog(std::string title, std::string filter, bool write);

bool palChoosePlatform(std::vector<PlatformInfo>& pi, int& pos, bool& newWnd, bool setDef = false);
void palSetRunFileName(std::string runFileName);
void palShowConfigWindow(int curTabId = 0);
void palUpdateConfig();

void palAddTabToConfigWindow(int tabId, std::string tabName);
void palRemoveTabFromConfigWindow(int tabId);
void palAddRadioSelectorToTab(int tabId, int column, std::string caption, std::string object, std::string property, SelectItem* items, int nItems);
void palSetTabOptFileName(int tabId, std::string optFileName);

void palRegisterSetPropValueCallbackFunc(bool (*func)(const std::string&, const std::string&, const std::string&));
void palRegisterGetPropertyStringValueFunc(std::string (*func)(const std::string&, const std::string&));

void palWxProcessMessages();

void palLog(std::string s);

class EmuLog
{
    public:
        EmuLog& operator<<(std::string s);
        EmuLog& operator<<(const char* sz);
        EmuLog& operator<<(int n);
};

extern EmuLog emuLog;

#endif // PALWX_H
