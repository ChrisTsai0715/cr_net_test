#include "net_connect_utils.h"
#include <getopt.h>

static void print_help()
{
    printf("-h : print this help;           \n"
           "-s : connect server domain;     \n"
           "-p : connect server port;       \n"
           "-i : bind interface, eg: eth1 or 192.168.1.1; can be empty;\n"
           "-t : timeout second;            \n");
}

int main(int argc, char** argv)
{
    const char* lpstrShotOpts = "hs:p:i:t:";
    int opt;

    std::string server_domain;
    int server_port = 0;
    std::string bind_interface;
    int timeout_ms = 3000;

    while ((opt = getopt(argc, argv, lpstrShotOpts)) > 0)
    {
        switch(opt)
        {
        case 'h':
            print_help();
            return 0;

        case 's':
            server_domain = optarg;
            break;

        case 'p':
            server_port = atoi(optarg);
            break;

        case 'i':
            bind_interface = optarg;
            break;

        case 't':
            timeout_ms = atoi(optarg) * 1000;
            break;
        }
    }


    if (server_domain.size() == 0 || server_port == 0)
    {
        print_help();
        return -3;
    }

    try
    {
        int ret = NETCONNECTUTILS(server_domain.c_str(), server_port, bind_interface.c_str(), timeout_ms);
        printf("connect to %s:%d %s\n", server_domain.c_str(), server_port, ret == NCR_OK ? "SUCCESS" : "FAILED");
        if (ret != NCR_OK)
            return -1;
    }
    catch (std::exception& e)
    {
        printf("connect to %s:%d error, reson:%s\n", server_domain.c_str(), server_port, e.what());
        return -2;
    }

    return 0;
}
