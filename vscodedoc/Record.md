${workspaceRoot} VS Code当前打开的文件夹

${file} 当前打开的文件

${relativeFile} 相对于workspaceRoot的相对路径

${fileBasename} 当前打开文件的文件名

${fileDirname} 所在的文件夹，是绝对路径

${fileExtname} 当前打开文件的拓展名，如.json

${cwd} the task runner's current working directory on startup

使用环境变量${env.Name} (e.g. ${env.PATH})，使用配置信息${config:python.pythonPath}

ctrl+shift+p呼出命令面板 可以输入task 执行具体任务 输入 debug执行debug输入compile编译.


tasks.json

{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    //ctrl shift p choose task
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "compile",
            "type": "shell",
            "command44": "echo ${cwd}",
            "command": "echo compile exeover&g++ -g  ${file} -o ${fileDirname}/${fileBasenameNoExtension}",
            // "command": "g++ ${file} -o ${fileDirname}/${fileBasenameNoExtension}&echo compile exeover&${fileDirname}/${fileBasenameNoExtension}",
            "cwd": "${workspaceFolder}",
            "problemMatcher1": [
                ""
            ],
            "presentation": {
                "reveal": "always",
                "panel": "new"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "label": "compileRun",
            "type": "shell",
            "command44": "echo ${cwd}",
            // "command": "echo compile exeover&g++ -g  ${file} -o ${fileDirname}/${fileBasenameNoExtension}",
            "command": "g++ -g ${file} -o ${fileDirname}/${fileBasenameNoExtension}&&echo [-----compileSucc----]&&${fileDirname}/${fileBasenameNoExtension}&&echo [----executeSucc----]",
            "args": [ //传递给命令的参数
                {
                //    "value": "",
                     "quoting": "escape" //指定对内容的escape
                }
            ],
            "problemMatcher": [
            ],

            
            "options": {
                "cwd": "${fileDirname}",
                "env": { //wsl的环境变量支持有问题，设置不生效
                    "MY_NAME": "aaaaaaa"
                },
                "shell": { //shell执行的一些配置
                    "executable": "bash",
                    "args": [
                        "-c"
                    ]
                },
            },

            "presentation": {
                "echo": false,//如果 为false,怎么执行命令是不会提示的,但是 程序里面的控制信息是会执行的.
                "reveal": "always",
                // "reveal": "never",//揭露 总是 显示信息不然搞毛.
                "focus": false,
                "panel": "shared",//面板就是每次启动的时候是否新开 dedicated专用 ,shared保留之前
                "clear": true,//每次变异 是否清屏.
                "showReuseMessage": false// 不是,true就提示enter,否则 还是需要按enter 就是提示那个英文而已但是并不会自动关闭
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}



launch.json



{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Launch",
            "cwd": "${workspaceFolder}",
            "type": "cppdbg",
            "request": "launch",
            "preLaunchTask": "compile",
            // "program3": "${workspaceRoot}/a.out",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            // "program": "${fileDirname}/${fileBasenameNoExtension}",
            "stopAtEntry": false,
            // "setupCommands": [
            //     {
            //         "description": "Enable pretty-printing for gdb",
            //         "text": "-enable-pretty-printing",
            //         "ignoreFailures": true
            //     }
            // ],
            // "customLaunchSetupCommands": [
            //     {
            //         "text": "target-run",
            //         "description": "run target",
            //         "ignoreFailures": false
            //     }
            // ],
            "launchCompleteCommand": "exec-run",
            "linux": {
                "MIMode": "gdb",
                "miDebuggerPath": "/usr/bin/gdb"
            },
            "osx": {
                "MIMode": "lldb"
            },
            "windows": {
                "MIMode": "gdb",
                "miDebuggerPath": "C:\\MinGw\\bin\\gdb.exe"
            }
        }
    ],
    "configurations1": [
        {
            "name": " Launch C",
            "type": "cppdbg",
            "request": "launch",
            "program": "{fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "preLaunchTask1": "compile",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gcc",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}


