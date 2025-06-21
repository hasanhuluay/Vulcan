#pragma once
#include <windows.h>
#include <vulkan/vulkan.h>
#include <vector>

// --- Minimal Vulkan Canvas Implementation
static VkRenderPass renderPass;
static VkFramebuffer framebuffer;
static VkCommandPool commandPool;
static VkCommandBuffer commandBuffer;
static VkSemaphore imageAvailableSemaphore;
static VkSemaphore renderFinishedSemaphore;
static VkFence inFlightFence;
static VkInstance instance;
static VkSurfaceKHR surface;
static VkPhysicalDevice physicalDevice;
static VkDevice device;
static VkQueue graphicsQueue;
static VkQueue presentQueue;
static VkSwapchainKHR swapchain;
static VkExtent2D extent;
static std::vector<VkImage> swapchainImages;
static std::vector<VkImageView> swapchainImageViews;
static std::vector<VkFramebuffer> framebuffers;


// Function declarations for Vulkan Canvas
void InitVulkanCanvas(HINSTANCE instance, HWND window);
void RenderVulkanCanvas();
void CleanupVulkanCanvas();
