#pragma once

#include <mbgl/storage/file_source.hpp>
#include <mbgl/storage/resource_options.hpp>
#include <mbgl/util/optional.hpp>

namespace mbgl {

class OnlineFileSource : public FileSource {
public:
    OnlineFileSource(const ResourceOptions& options);
    ~OnlineFileSource() override;
    void setResourceOptions(ResourceOptions) override;
    ResourceOptions getResourceOptions() override;    

private:
    // FileSource overrides
    std::unique_ptr<AsyncRequest> request(const Resource&, Callback) override;
    bool canRequest(const Resource&) const override;
    void pause() override;
    void resume() override;
    void setProperty(const std::string&, const mapbox::base::Value&) override;
    mapbox::base::Value getProperty(const std::string&) const override;
    void setResourceTransform(ResourceTransform) override;

    class Impl;
    const std::unique_ptr<Impl> impl;
};

} // namespace mbgl
