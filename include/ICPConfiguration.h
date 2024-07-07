#pragma once

/**
 * enum for correspondence method: nearest neighbor or projective
 */
enum CorrMethod
{
    ANN,
    PROJ,
};

/**
 * ICP Configuration.
 */
class ICPConfiguration
{
public:
    // Task
    bool runShapeICP = false;
    bool runSequenceICP = false;
    // ICP type
    bool useLinearICP = false;
    // ICP objective(s)
    bool usePointToPoint = false;
    double weightPointToPoint = 1.;
    bool usePointToPlane = false;
    double weightPointToPlane = 1.;
    bool useSymmetric = false;
    double weightSymmetric = 1.;
    // Whether to use color information.
    bool useColor = false;
    // Correspondence method (ANN / PROJ)
    CorrMethod correspondenceMethod = ANN;
    // Other settings
    float matchingMaxDistance = 0.0f;
    int nbOfIterations = 0;

    void loadFromYaml(const std::string &filename);
    void show();

private:
    void _loadFromYaml(const std::string &filename);
    void _sanityCheck();
};