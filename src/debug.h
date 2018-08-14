
void vk_check_failure(const char* file, int line, const char* invocation);

#define VK_CHECK(call) \
{ \
    VkResult result = call; \
    if(result != VK_SUCCESS) { \
        vk_check_failure(__FILE__, __LINE__, #call); \
    } \
}
