#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <dirent.h>
using namespace std;

int main(void) {
    freopen("../README.md", "w", stdout);
    puts("## Solutions to LeetCode Programming Problems\n\n");
    DIR *dir;
    char *directoryPath = "/Users/kaidul/Documents/LeetCode_problems_solution/source-code/";
    struct dirent *ent;
    if ((dir = opendir (directoryPath)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            int n = strlen(ent->d_name);
            if(n < 4) {
                continue;
            }
            char filename[260];
            for(int i = 0; i < n; ++i) {
                if(ent->d_name[i] == '_')
                    filename[i] = ' ';
                else filename[i] = ent->d_name[i];
            }
            filename[strlen(ent->d_name)] = '\0';
            string sFileName = string(filename);
            int dot = sFileName.find('.');
            assert(dot != string::npos);
            sFileName = sFileName.substr(0, dot);
            printf("+ [%s](source-code/%s)\n", sFileName.c_str(), ent->d_name);
            // int result = rename(ent->d_name, filename);
            // if(result == 0) puts ( "File successfully renamed" );
            // else perror( "Error renaming file" );
//            printf ("%s, %s\n", ent->d_name, filename); // foo bar, foo_bar
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
    return 0;
}