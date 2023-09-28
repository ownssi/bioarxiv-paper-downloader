#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;

    fp = fopen("pdfs.txt","r");
    size_t row_index = 0;
    char **urls = NULL;


    size_t len_index = 0;
    urls[row_index] = malloc(sizeof(char));
    while(1){
        char c = fgetc(fp);
        
        if( feof(fp) ) { 
            break;
        }
        else if(c == '\n'){
            urls[row_index][len_index] = '\0';
            row_index++;
            urls = realloc(urls,((row_index+1) * sizeof(char*)));
            len_index = 0;
            continue;
        }
        urls[row_index] = realloc(urls[row_index],((len_index+1) * sizeof(char)));
        urls[row_index][len_index] = c;
        len_index++;
    }
    fclose(fp);

    printf("%s",urls[0]);

    /*
      fp = fopen("file.pdf","wb");

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL,urls[0]);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);

    int result;
    result = curl_easy_perform(curl);

    if(result == CURLE_OK)
        printf("Downloaded!\n");
    else
        printf("Failed\n");
    
    fclose(fp);
    curl_easy_cleanup(curl);
    */
  
    return 0;
}