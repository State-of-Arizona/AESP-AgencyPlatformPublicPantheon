<?php

declare(strict_types=1);

namespace SimpleSAML\XML;

use DOMAttr;
use DOMElement;
use SimpleSAML\Assert\Assert;

use function array_keys;

/**
 * Class to represent an arbitrary namespaced attribute.
 *
 * @package simplesamlphp/xml-common
 */
final class Attribute implements ArrayizableElementInterface
{
    /**
     * Create an Attribute class
     *
     * @param string|null $namespaceURI
     * @param string $namespacePrefix
     * @param string $attrName
     * @param string $attrValue
     */
    public function __construct(
        protected ?string $namespaceURI,
        protected string $namespacePrefix,
        protected string $attrName,
        protected string $attrValue,
    ) {
        Assert::nullOrStringNotEmpty($namespaceURI);
        Assert::string($namespacePrefix);
        Assert::notSame('xmlns', $namespacePrefix);
        if ($namespaceURI !== null) {
            Assert::stringNotEmpty($namespacePrefix);
        }
        Assert::stringNotEmpty($attrName);
        Assert::string($attrValue);
    }


    /**
     * Collect the value of the namespaceURI-property
     *
     * @return string|null
     */
    public function getNamespaceURI(): ?string
    {
        return $this->namespaceURI;
    }


    /**
     * Collect the value of the namespacePrefix-property
     *
     * @return string
     */
    public function getNamespacePrefix(): string
    {
        return $this->namespacePrefix;
    }


    /**
     * Collect the value of the localName-property
     *
     * @return string
     */
    public function getAttrName(): string
    {
        return $this->attrName;
    }


    /**
     * Collect the value of the value-property
     *
     * @return string
     */
    public function getAttrValue(): string
    {
        return $this->attrValue;
    }


    /**
     * Create a class from XML
     *
     * @param \DOMAttr $xml
     * @return static
     */
    public static function fromXML(DOMAttr $attr): static
    {
        return new static($attr->namespaceURI, $attr->prefix, $attr->localName, $attr->value);
    }



    /**
     * Create XML from this class
     *
     * @param \DOMElement $parent
     * @return \DOMElement
     */
    public function toXML(DOMElement $parent): DOMElement
    {
        $parent->setAttributeNS(
            $this->getNamespaceURI(),
            $this->getNamespacePrefix() . ':' . $this->getAttrName(),
            $this->getAttrValue(),
        );

        return $parent;
    }


    /**
     * Create a class from an array
     *
     * @param array $data
     * @return static
     */
    public static function fromArray(array $data): static
    {
        $data = self::processArrayContents($data);

        return new static(
            $data['namespaceURI'],
            $data['namespacePrefix'],
            $data['attrName'],
            $data['attrValue'],
        );
    }


    /**
     * Validates an array representation of this object and returns the same array with rationalized keys
     *
     * @param array $data
     * @return array
     */
    private static function processArrayContents(array $data): array
    {
        $data = array_change_key_case($data, CASE_LOWER);

        Assert::allOneOf(
            array_keys($data),
            ['namespaceuri', 'namespaceprefix', 'attrname', 'attrvalue'],
        );

        Assert::keyExists($data, 'namespaceuri');
        Assert::keyExists($data, 'namespaceprefix');
        Assert::keyExists($data, 'attrname');
        Assert::keyExists($data, 'attrvalue');

        Assert::nullOrStringNotEmpty($data['namespaceuri']);
        Assert::string($data['namespaceprefix']);
        Assert::stringNotEmpty($data['attrname']);
        Assert::string($data['attrvalue']);

        return [
            'namespaceURI' => $data['namespaceuri'],
            'namespacePrefix' => $data['namespaceprefix'],
            'attrName' => $data['attrname'],
            'attrValue' => $data['attrvalue'],
        ];
    }


    /**
     * Create an array from this class
     *
     * @return array{attrName: string, attrValue: string, namespacePrefix: string, namespaceURI: null|string}
     */
    public function toArray(): array
    {
        return [
            'namespaceURI' => $this->getNamespaceURI(),
            'namespacePrefix' => $this->getNamespacePrefix(),
            'attrName' => $this->getAttrName(),
            'attrValue' => $this->getAttrValue(),
        ];
    }
}
