#include "chardev.h"

int main (){
    Scene sce;
    cpng wifi;
    wifi.id_cpng = 1;
    wifi.name = "wifi_logo";
    ini_game(&sce);
    sce.hiddenCursor(0);
    sce.addTitleConsole("Show wifi logo(chardev)");
    sce.readDraw(&wifi);
    READKEY();
    return 0;
}
