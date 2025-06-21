#include <windows.h>
#include "VulkanCanvas.h"  // Declare Vulkan logic here

LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_DESTROY) PostQuitMessage(0);
    return DefWindowProc(window, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int showCommand) {
    const wchar_t* windowClassName = L"MinimalWindowClass";

    WNDCLASS windowClass = {};
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = instance;
    windowClass.lpszClassName = windowClassName;
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&windowClass);

    HWND window = CreateWindowEx(
        0, windowClassName, L"Vulkan Window", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr, nullptr, instance, nullptr
    );

    if (!window) return 0;

    ShowWindow(window, showCommand);

    // --- Initialize Vulkan
    InitVulkanCanvas(instance, window);

    // --- Main message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        RenderVulkanCanvas();  // Call Vulkan render every frame
    }

    CleanupVulkanCanvas(); // Optional cleanup at exit
    return 0;
}
