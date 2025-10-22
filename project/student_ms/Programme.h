//
// Created by PC on 2025/10/22.
//

#ifndef DSA_PROGRAMME_H
#define DSA_PROGRAMME_H

#include "Manager.h"

namespace ms {

    class Programme {
    public:
        Programme();
        void Exec();
    private:
        struct CommandInfo {
            std::string cmd;
            int required_argc;
            std::string format;
            bool (Programme::*handler)(const std::vector<std::string> &args);
        };
        std::unordered_map<std::string, CommandInfo> commands;
        Logger log_;
        StudentManager manager_;
        void RegisterCommand(const CommandInfo& ci);
        bool RunCommand(const std::string& cmd, const std::vector<std::string>& args);
        bool RunExit(const std::vector<std::string>& args);
        bool RunCreate(const std::vector<std::string>& args);
        bool RunModify(const std::vector<std::string>& args);
        bool RunFind(const std::vector<std::string>& args);
        bool RunSort(const std::vector<std::string>& args);
        bool RunRemove(const std::vector<std::string>& args);
        bool RunLoad(const std::vector<std::string>& args);
        bool RunSave(const std::vector<std::string>& args);
        bool RunHelp(const std::vector<std::string>& args);
        bool RunPrint(const std::vector<std::string>& args);
    };

}


#endif //DSA_PROGRAMME_H