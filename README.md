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
<details>
<summary>Show The Example</summary>
<p align="center">
  <img src="https://github.com/fsb3rke/todocli/blob/master/images/addTask.png?raw=true" width="580" title="addTask example">
</p>
</details>

### List All Tasks
```sh
todocli list
```
<details>
<summary>Show The Example</summary>
<p align="center">
  <img src="https://github.com/fsb3rke/todocli/blob/master/images/listTasks.png?raw=true" width="580" title="listTasks example">
</p>
</details>

### Change Spesific Task Status
#### Flags
| Complete | UnComplete |
| -------- | ---------- |
| `--c` | `--u` |
```sh
todocli status flag 0
```
<details>
<summary>Show The Examples</summary>
--c
<p align="center">
  <img src="https://github.com/fsb3rke/todocli/blob/master/images/statusCompleted.png?raw=true" width="580" title="addTask example">
</p>
--u
<p align="center">
  <img src="https://github.com/fsb3rke/todocli/blob/master/images/statusUnCompleted.png?raw=true" width="580" title="addTask example">
</p>
</details>

### Remove Spesific Task
```sh
todocli remove 0
```
<details>
<summary>Show The Example</summary>
<p align="center">
  <img src="https://github.com/fsb3rke/todocli/blob/master/images/removeTask.png?raw=true" width="580" title="addTask example">
</p>
</details>



 ## Installation
Github to clone the project.
```sh
git clone https://github.com/fsb3rke/todocli.git
```
Cli to clone the project.
```sh
gh repo clone fsb3rke/todocli
```
Get Build Folder For CMake
```sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build -G"Unix Makefiles"
```
Build Todocli
```sh
make
```

## RoadMap
- Header System

## License
Copyright (c) 2023 Berke Avcı (fsb3rke) \
\
This software is released under the [MIT](https://choosealicense.com/licenses/mit/) License.
