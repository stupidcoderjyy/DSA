//
// Created by PC on 2025/10/22.
//

#include <iomanip>
#include <ranges>
#include <sstream>

#include "Programme.h"

namespace ms {

    Programme::Programme() : log_("system.log"), manager_(log_) {
        RegisterCommand({"exit", 0, "", &Programme::RunExit});
        RegisterCommand({"add", 5,
            "<id:string[1,10]> <name:string[1,20]> <age:int[0,INT_MAX]> <score:int[0,INT_MAX]> <class:A|B|C>",
            &Programme::RunCreate});
        RegisterCommand({"mod", 3,
            "<id:string[1,10]> <key:name|age|score|clazz> <val>",
            &Programme::RunModify});
        RegisterCommand({"find", 2, "<search_type:id|name|score|class> <arg>", &Programme::RunFind});
        RegisterCommand({"remove", 1, "<id:string>", &Programme::RunRemove});
        RegisterCommand({"sort", 1, "<sort_type:id|name|score|class> <print:true|false>[false]", &Programme::RunSort});
        RegisterCommand({"load", 1, "<path:string>", &Programme::RunLoad});
        RegisterCommand({"save", 0, "", &Programme::RunSave});
        RegisterCommand({"help", 0, "", &Programme::RunHelp});
        RegisterCommand({"print", 0, "", &Programme::RunPrint});
    }

    void Programme::Exec() {
        while (true) {
            std::cout << "\nms:";
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            std::string cmd, arg;
            ss >> cmd;
            if (cmd.empty()) {
                continue;
            }
            std::vector<std::string> args;
            while (ss >> arg) {
                if (arg.size() > 1 && arg.front() == '\"' && arg.back() == '\"') {
                    arg = arg.substr(1, arg.size() - 2);
                }
                args.push_back(arg);
            }
            if (RunCommand(cmd, args)) {
                break;
            }
        }
    }

    void Programme::RegisterCommand(CommandInfo ci) {
        commands[ci.cmd] = std::move(ci);
    }

    bool Programme::RunCommand(const std::string &cmd, const std::vector<std::string> &args) {
        try {
            if (!commands.contains(cmd)) {
                throw std::runtime_error("unknown command");
            }
            const auto& ci = commands[cmd];
            if (!args.empty() && args[0] == "help") {
                std::cout << "format: " << ci.format << std::endl;
                return false;
            }
            if (args.size() < ci.required_argc) {
                throw std::runtime_error("requires " + std::to_string(ci.required_argc) + " args: " + ci.format);
            }
            return (this->*commands[cmd].handler)(args);
        } catch (std::exception& e) {
            log_.Error() << "failed to execute command '" << cmd << "': " << e.what() << std::endl;
            return false;
        }
    }

    bool Programme::RunExit(const std::vector<std::string> &args) {
        log_.Info() << "Closing ..." << std::endl;
        return true;
    }

    bool Programme::RunCreate(const std::vector<std::string> &args) {
        manager_.Create(args[0], args[1], args[2], args[3], args[4]);
        return false;
    }

    bool Programme::RunModify(const std::vector<std::string> &args) {
        manager_.Modify(args[0], args[1], args[2]);
        return false;
    }

    bool Programme::RunFind(const std::vector<std::string> &args) {
        manager_.Search(args[0], args[1]);
        return false;
    }

    bool Programme::RunSort(const std::vector<std::string> &args) {
        manager_.Sort(args[0], args.size() > 1 && args[1] == "true");
        return false;
    }

    bool Programme::RunRemove(const std::vector<std::string> &args) {
        manager_.Remove(args[0]);
        return false;
    }

    bool Programme::RunLoad(const std::vector<std::string> &args) {
        manager_.Load(args[0]);
        return false;
    }

    bool Programme::RunSave(const std::vector<std::string> &args) {
        manager_.Save();
        return false;
    }

    bool Programme::RunHelp(const std::vector<std::string> &args) {
        auto& log = log_.Info();
        for (const auto &ci: commands | std::views::values) {
             log << std::setw(15) << std::left << ci.cmd << ci.format << '\n';
        }
        log.flush();
        return false;
    }

    bool Programme::RunPrint(const std::vector<std::string> &args) {
        manager_.Print();
        return false;
    }
}
