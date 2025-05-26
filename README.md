# VR 3D Model Viewer – Nanite Conversion & Streaming

## Overview

This project aims to provide a user-friendly tool to visualize highly detailed photogrammetric 3D models in virtual reality using Unreal Engine 5. It focuses on enabling Earth Sciences students and faculty to explore 3D models without requiring technical expertise.

The system automates the conversion, optimization (via Nanite), and packaging of massive 3D models, allowing seamless deployment in VR without needing users to install complex dependencies.

## Repositories

* 🔁 **FBXCloudConverter** – Convert photogrammetric models to `.FBX` format using CloudCompare
  🔗 [https://github.com/jagv94/FBXCloudConverter](https://github.com/jagv94/FBXCloudConverter)

* 🧱 **NaniteConverter** – Convert `.FBX` to Nanite meshes, cook them, and package into `.PAK` files
  🔗 [https://github.com/jagv94/NaniteConverter](https://github.com/jagv94/NaniteConverter)

---

## Project Goals

* Enable VR visualization of photogrammetric models with >64 million triangles
* Preserve geometric accuracy for academic measurements
* Provide a no-installation-needed workflow for non-technical users
* Automate the model processing pipeline: from photogrammetry output to VR display

---

## Why Unreal Engine?

Unreal Engine 5 was selected over Unity due to:

* **Nanite support** – Automatically optimizes high-poly meshes without needing manual LOD creation
* **Superior performance** – Handles billions of triangles in real-time VR environments

Other tools like Cesium were considered but discarded due to:

* Latency issues when streaming large models
* Manual LOD generation requirements
* Use of proprietary formats (3D Tiles), adding conversion overhead

---

## Workflow Summary

1. **Photogrammetry Model Input**
   Models are processed into `.FBX` using the [FBXCloudConverter](https://github.com/jagv94/FBXCloudConverter).

2. **Model Conversion and Optimization**
   Using the [NaniteConverter](https://github.com/jagv94/NaniteConverter), models are:

   * Converted to Nanite Static Meshes
   * Cooked for runtime deployment
   * Packaged into `.PAK` files for loading into the VR viewer

3. **VR Visualization**
   The packaged models are loaded into an Unreal VR project where users can inspect them interactively.

---

## Key Features

* 🔄 **Automated Model Conversion**: Drag-and-drop style processing for non-technical users
* ⚙️ **Nanite Integration**: Supports large, high-detail models with excellent performance
* 📆 **PAK Packaging**: Models are bundled for easy deployment and sharing

---

## Limitations & Future Work

* The current system requires Unreal Engine 5.4.4 for model cooking and Nanite support
* Some functionality (e.g., `.PAK` import plugin) is still in development or partially implemented
* The `.FBX` to Nanite pipeline is currently adapted for a specific output format and may need expansion for wider compatibility

---

## Installation

1. **Clone both repositories**

   ```bash
   git clone https://github.com/jagv94/FBXCloudConverter.git
   git clone https://github.com/jagv94/NaniteConverter.git
   ```

2. **Follow the setup instructions in each repository’s README**

---
