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

#ifndef EMUCONFIG_H
#define EMUCONFIG_H

#include <list>
#include <map>

#include "EmuTypes.h"
#include "EmuObjects.h"


class EmuConfig : public EmuObject
{
    public:
        EmuConfig();

        void addPlatform(std::string platformName, std::string configFileName, std::string objName, std::string cmdLineOption);
        void addExtention(std::string extention, std::string objName);

        bool setProperty(const std::string& propertyName, const EmuValuesList& values) override;

        bool choosePlatform(PlatformInfo& pi, std::string curPlatformName, bool& newWnd, bool setDefault = false);
        void showConfigWindow(int configTabId = 0);
        void updateConfig();

        std::vector<PlatformInfo>* getPlatformInfos() {return &m_platformVector;};
        std::map<std::string, std::string>* getExtentionMap() {return &m_extentionMap;};

    private:
        std::vector<PlatformInfo> m_platformVector;
        std::map<std::string, std::string> m_extentionMap;
};


class EmuConfigControl : public EmuObject
{

};


class EmuConfigRadioSelector : public EmuConfigControl
{
    public:
        EmuConfigRadioSelector(std::string objName, std::string propName, std::string caption);
        ~EmuConfigRadioSelector();

        void addItem(std::string value, std::string name);

        SelectItem* getItems();
        int getNItems();
        std::string getCaption();
        std::string getObjName();
        std::string getPropName();

        bool setProperty(const std::string& propertyName, const EmuValuesList& values) override;

    private:
        std::string m_objName;
        std::string m_propName;
        std::string m_caption;
        std::vector<SelectItem> m_selectItemVector;

};


struct ControlInfo
{
    int column;
    EmuConfigControl* control;
};


class EmuConfigTab : public EmuObject
{
    public:
        EmuConfigTab(std::string tabName);
        ~EmuConfigTab();

        void addControl(int column, EmuConfigControl* control);
        int getTabId() {return m_tabId;};

        bool setProperty(const std::string& propertyName, const EmuValuesList& values) override;

    private:
        static int s_curId;

        int m_tabId;

        std::vector<ControlInfo> m_configControlVector;
};


#endif  // EMUCONFIG_H
