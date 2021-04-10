/* Acknowledgement: this solution is inspired by the following article
https://blog.csdn.net/qq_43381135/article/details/112953778 */

#include <climits>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

// Global variables
const int MAX_NUM = 1e5 + 5;
static int num = 0;               // total number of nodes
vector<pair<int, string>> recall; // store temporary path in case cannot create new file

typedef struct node node;
struct node
{
    int parent;             // id of its parent node
    map<string, int> child; // a map consisting of its children and mapping their name to their id
    bool is_directory;      // true if it is a directory node, false if it is a file node
    ll ldir, ldes;          // maximum space for files in this directory and for its descendents
    ll ldir_u, ldes_u;      // used space for files...
    int size;               // size for a file
} a[MAX_NUM];               // the index of an element is also the unique id of the node

void roll_back()
{
    // index and name of files to be erased
    int id;
    string name;
    for (int i = 0; i < recall.size(); i++)
    {
        id = recall[i].fi;
        name = recall[i].se;
        a[id].child.erase(a[id].child.find(name));
    }
    recall.clear();
}

char create_file()
{
    // path and size of the file to be created
    string filepath;
    int filesize;
    cin >> filepath >> filesize;

    // parse the path to separate file name from the file path
    int splitter = filepath.size() - 1;
    while (splitter && filepath[splitter] != '/')
    {
        splitter--;
    }

    // get ready to create new file
    recall.clear();           // clear the recall vector
    int num_bak = num;        // back up global variable
    int next_dir_pointer = 0; // pointer to the next "working" directory
    string next_dir;          // name of next directory
    int cur_id = 0;           // starting from the root

    // begin to create file
    while (next_dir_pointer < splitter)
    {
        next_dir = "";      // clear the directory
        next_dir_pointer++; // every time the loop finishes, this pointer points to a '/'

        // deal with the path
        while (next_dir_pointer < splitter && filepath[next_dir_pointer] != '/')
        {
            next_dir += filepath[next_dir_pointer];
            next_dir_pointer++;
        }
        if (a[cur_id].child.find(next_dir) == a[cur_id].child.end()) // cannot find next "working" directory, create it
        {
            a[cur_id].child[next_dir] = ++num; // create a new node
            a[num].parent = cur_id;
            a[num].is_directory = 1;
            a[num].ldir = a[num].ldes = LLONG_MAX;
            a[num].ldir_u = a[num].ldes_u = 0;
            a[num].size = 0;
            recall.pb(mp(cur_id, next_dir)); // new node to be recalled, mapping index of parent to name of child
            cur_id = num;                    // "move" to current directory
        }
        else
        {
            int child_id = a[cur_id].child[next_dir]; // get index of this child node
            if (!a[child_id].is_directory)            // if child is not a directory
            {
                roll_back();   // failed, roll back path
                num = num_bak; // roll back global variable num
                return 'N';
            }
            cur_id = child_id; // update current "working" directory
        }
    }

    // deal with the file
    next_dir = "";
    for (next_dir_pointer++; next_dir_pointer < filepath.size(); next_dir_pointer++)
    {
        next_dir += filepath[next_dir_pointer];
    }
    bool is_new = a[cur_id].child.find(next_dir) == a[cur_id].child.end();
    if (!is_new) // this file exist, but we do not want it to be a directory
    {
        int child_id = a[cur_id].child[next_dir];
        if (a[child_id].is_directory)
        {
            roll_back(); // not to mention a second time, see line 92-94
            num = num_bak;
            return 'N';
        }
    }
    ll delta_size = filesize - (is_new ? 0 : a[a[cur_id].child[next_dir]].size); // now let's take a look at the space change, whether creating or modifying a file
    if (a[cur_id].ldir_u + delta_size > a[cur_id].ldir)                          // exceed current directory space limit
    {
        roll_back(); // not to mention a second time, see line 92-94
        num = num_bak;
        return 'N';
    }
    int back_id = cur_id; // go back to check parents' space limit on descendents
    while (back_id != -1) // stop when going back to root
    {
        if (a[back_id].ldes_u + delta_size > a[back_id].ldes) // exceed descendent space limit
        {
            roll_back(); // not to mention a second time, see line 92-94
            num = num_bak;
            return 'N';
        }
        back_id = a[back_id].parent; // go upwards
    }
    if (is_new)
    {
        a[cur_id].child[next_dir] = ++num;
        a[num].parent = cur_id;
        a[num].is_directory = 0;
        a[num].size = filesize;
    }
    else
    {
        a[a[cur_id].child[next_dir]].size += delta_size;
    }
    a[cur_id].ldir_u += delta_size;
    back_id = cur_id;     // go back to check parents' space limit on descendents
    while (back_id != -1) // stop when going back to root
    {
        a[back_id].ldes_u += delta_size;
        back_id = a[back_id].parent; // go upwards
    }
    return 'Y';
}

char delete_file()
{
    // path of the file to be deleted
    string filepath;
    cin >> filepath;

    // parse the path to separate file name from the file path
    int splitter = filepath.size() - 1;
    while (splitter && filepath[splitter] != '/')
    {
        splitter--;
    }

    // get ready to delete the file, but we do not need the recall vector, just stop when a directory does not exist
    int next_dir_pointer = 0; // pointer to the next "working" directory
    string next_dir;          // name of next directory
    int cur_id = 0;           // starting from the root

    // begin to delete file
    while (next_dir_pointer < splitter)
    {
        next_dir = "";      // clear the directory
        next_dir_pointer++; // every time the loop finishes, this pointer points to a '/'

        // deal with the path
        while (next_dir_pointer < splitter && filepath[next_dir_pointer] != '/')
        {
            next_dir += filepath[next_dir_pointer];
            next_dir_pointer++;
        }
        if (a[cur_id].child.find(next_dir) == a[cur_id].child.end()) // cannot find next "working" directory, just happily stop
        {
            return 'Y';
        }
        else
        {
            int child_id = a[cur_id].child[next_dir]; // get index of this child node
            if (!a[child_id].is_directory)            // if child is not a directory, we cannot step further, so happily stop
            {
                return 'Y';
            }
            cur_id = child_id; // update current "working" directory
        }
    }

    // deal with the file
    next_dir = "";
    for (next_dir_pointer++; next_dir_pointer < filepath.size(); next_dir_pointer++)
    {
        next_dir += filepath[next_dir_pointer];
    }
    int child_id = a[cur_id].child[next_dir];
    ll delta_size;
    if (!a[child_id].is_directory)
    {
        delta_size = -a[child_id].size;
        a[cur_id].ldir_u += delta_size;
    }
    else
    {
        delta_size = -a[child_id].ldes_u;
    }
    a[cur_id].child.erase(a[cur_id].child.find(next_dir)); // for simplicity, do not deal with its descendents if the file to be deleted is a directory, though this may cause a memory leak bug

    // go upwards to update memory usage information
    int back_id = cur_id;
    while (back_id != -1) // stop when going back to root
    {
        a[back_id].ldes_u += delta_size;
        back_id = a[back_id].parent; // go upwards
    }
    return 'Y';
}

char change_restriction()
{
    // path and space to be changed
    string filepath;
    ll new_ldir, new_ldes;
    cin >> filepath >> new_ldir >> new_ldes;
    if (!new_ldir)
    {
        new_ldir = LLONG_MAX;
    }
    if (!new_ldes)
    {
        new_ldes = LLONG_MAX;
    }

    // parse the path to separate file name from the file path
    int splitter = filepath.size() - 1;
    while (splitter && filepath[splitter] != '/')
    {
        splitter--;
    }

    // get ready to change restriction, similar to line 173-175
    int next_dir_pointer = 0; // pointer to the next "working" directory
    string next_dir;          // name of next directory
    int cur_id = 0;           // starting from the root

    // begin to change space restriction
    while (next_dir_pointer < splitter)
    {
        next_dir = "";      // clear the directory
        next_dir_pointer++; // every time the loop finishes, this pointer points to a '/'

        // deal with the path
        while (next_dir_pointer < splitter && filepath[next_dir_pointer] != '/')
        {
            next_dir += filepath[next_dir_pointer];
            next_dir_pointer++;
        }
        if (a[cur_id].child.find(next_dir) == a[cur_id].child.end()) // cannot find next "working" directory
        {
            return 'N';
        }
        else
        {
            int child_id = a[cur_id].child[next_dir]; // get index of this child node
            if (!a[child_id].is_directory)            // if child is not a directory, we cannot step further
            {
                return 'N';
            }
            cur_id = child_id; // update current "working" directory
        }
    }

    // deal with the file
    next_dir = "";
    for (next_dir_pointer++; next_dir_pointer < filepath.size(); next_dir_pointer++)
    {
        next_dir += filepath[next_dir_pointer];
    }
    int change_id;
    if (next_dir == "") // if change restriction of root
    {
        change_id = 0;
    }
    else
    {
        if (a[cur_id].child.find(next_dir) == a[cur_id].child.end()) // cannot find the directory
        {
            return 'N';
        }
        change_id = a[cur_id].child[next_dir];
    }
    if (!a[change_id].is_directory || new_ldir < a[change_id].ldir_u || new_ldes < a[change_id].ldes_u) // the file is not directory or cannot change space restriction
    {
        return 'N';
    }
    a[change_id].ldir_u = new_ldir;
    a[change_id].ldes_u = new_ldes;
    return 'Y';
}

int main()
{
    // initialize root node
    a[num].parent = -1;
    a[num].is_directory = 1;
    a[num].ldir = a[num].ldes = LLONG_MAX;
    a[num].ldir_u = a[num].ldes_u = 0;
    a[num].size = 0;

    // deal with commands
    int n;
    char op;
    cin >> n;
    while (n--)
    {
        cin >> op;
        switch (op)
        {
        case 'C':
            cout << create_file() << endl;
            break;
        case 'R':
            cout << delete_file() << endl;
            break;
        case 'Q':
            cout << change_restriction() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
