
#ifdef SSENGINE_PROJECT
    #define SSENGINECLASS __declspec(dllexport)
#else
    #define SSENGINECLASS __declspec(dllimport)
#endif

#ifdef DBENGINE_PROJECT
    #define DBENGINECLASS __declspec(dllexport)
#else
    #define DBENGINECLASS __declspec(dllimport)
#endif
