# C/C++ DSA Practice

## Folder Structure

```text
.
├── arrays/
│   └── test.cpp
├── graphs/
│   ├── 00graph_utils.cpp
│   ├── 00graph_utils.h
│   ├── 00seed_data.cpp
│   ├── 01adj_matrix.cpp
│   ├── 02adj_list.cpp
│   ├── 03connected_comp.tle.cpp
│   ├── 04bfs.cpp
│   └── Solution.cpp
├── test.c
└── README.md
```

## Run C++

### Arrays

```bash
g++ arrays/test.cpp -o arrays_test
./arrays_test
```

### Adjacency Matrix

```bash
g++ graphs/01adj_matrix.cpp -o adj_matrix
./adj_matrix
```

### Adjacency List

```bash
g++ graphs/02adj_list.cpp -o adj_list
./adj_list
```

### Random Graph

```bash
g++ graphs/00seed_data.cpp -o seed_data
./seed_data
```

### BFS

```bash
g++ graphs/04bfs.cpp graphs/00graph_utils.cpp -o bfs
./bfs
```

## Run C

```bash
gcc test.c -o test
./test
```

> On Windows, run executables as `test.exe`, `bfs.exe`, etc.
