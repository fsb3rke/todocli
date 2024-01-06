# todocli
Simple todo app. Designed for people who uses command line. 

## Usage
Start with terminal
```sh
todocli
```

## Commands & Usages

## Command List
| Initialize | Add Task | Remove Task | List Tasks | Set Status Task |
| ---------- | -------- | ----------- | ---------- | --------------- |
| todocli init | todocli add TASK | todocli remove INDEX | todocli list | todocli status FLAG INDEX |

### Create Init file
```sh
todocli init
```

### Add Task
```sh
todocli add fsb3rke is a good developer
```

### List All Tasks
```sh
todocli list
```

### Change Spesific Task Status
#### Flags
| Complete | UnComplete |
| -------- | ---------- |
| `--c` | `--u` |
```sh
todocli status flag 0
```

### Remove Spesific Task
```sh
todocli remove 0
```



 ## Installation
Github to clone the project.
```sh
git clone https://github.com/fsb3rke/todocli.git
```
Cli to clone the project.
```sh
gh repo clone fsb3rke/todocli
```

#### WINDOWS
POWERSHELL
```
./build.bat
```
CMD
```
build.bat
```

#### LINUX
First, bash file needs to ``chmod 777`` to be an executable file.
```sh
chmod 777 ./build.sh
```
You can execute the bash file.
```sh
./build.sh
```

## RoadMap
- Header System

## License
Copyright (c) 2023 Berke Avcı (fsb3rke) \
\
This software is released under the [MIT](https://choosealicense.com/licenses/mit/) License.
